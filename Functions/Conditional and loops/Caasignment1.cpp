#include<stdio.h>
#include<string.h>

int main()
{
    char ch[20];
    int len, i, j;
    printf("Enter a string: ");
    gets(ch);
    len = strlen(ch);

    for(i=0;i<=len;i++)
    {
        for(j=0;j<i;j++)
        {
            printf(" %c",ch[j]);
        }
        printf("\n");
    }
    for(i=len-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            printf(" %c",ch[j]);
        }
        printf("\n");
    }
}