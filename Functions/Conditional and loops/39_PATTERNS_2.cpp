#include<stdio.h>
/*#include<string.h>

char a[20];*/

int main()
/*{
	int i,j;
	printf("Enter a string: ");
	scanf("%s",&a);
	int len=strlen(a);
	for(i=1;i<=len;i++)
	{
		for(j=1;j<=len;j++)
		{
			printf("%s",a[len]);
		}
		printf("\n");
	}
}*/
{
	int i,j,k,n=3;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf(" %c",'a'+ j);
			for(k=3;k<j;k++)
			{
				printf("%c",'d'- k);
			}
		}
		printf("\n");
	}
}