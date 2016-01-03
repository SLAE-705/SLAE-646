global _start

section .data
            egg equ "egg_"

section .text
_start:
        pop eax
        compare:
                cmp dword [eax], egg
                jnz not_found
                cmp dword [eax+4], egg
                jnz not_found
                jmp found
        not_found:
                inc  eax
                jmp compare
        found:
                add eax,8
                jmp eax

