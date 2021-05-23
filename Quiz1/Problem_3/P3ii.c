
//For 16 32-bit integers
#include <stdio.h>

int main()
{
    char x[64];
    int *ptr;
    ptr = (int *)x;
    for (int i = 0; i < 16; i++)
    {
        int num;
        printf("enter integer %d : ", i + 1);
        scanf("%d", &num);
        *ptr = num;
        ++ptr;
    }
    ptr = (int *)x;                     //reset the pointer
    for (int i = 0; i < 16; i++)
    {
        printf("%d \n", *ptr);
        ++ptr;
    }
    return 0;
}
