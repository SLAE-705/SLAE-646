int main()
{
    unsigned char worst_case[]={"0x01,0xfe"};
    printf("The original state of the array: \n%x\n", worst_case[0]);
    printf("%x\n\n", worst_case[1]);

    //The operations cause a underflow/overflow
    worst_case[0]=worst_case[0]-4;
    worst_case[1]=worst_case[1]+4;
    //Do the the reverse operation
    worst_case[0]=worst_case[0]+4;
    worst_case[1]=worst_case[1]-4;

    printf("The result after the operations: \n");
    printf("%x\n", worst_case[0]);
    printf("%x", worst_case[1]);

}
