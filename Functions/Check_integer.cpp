#include<stdio.h>
void check_integer(int num);
int main()
{
    signed int num=0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    check_integer(num);
}

void check_integer(int num)
{
    if (num < 0)
    {
        printf("The number is negative.\n");
        
    }
    else if(num>0)
    {
       printf("The number is positive.\n");
    }
    else if(num==0)
    {
        printf("The number is zero.\n");
    }
}