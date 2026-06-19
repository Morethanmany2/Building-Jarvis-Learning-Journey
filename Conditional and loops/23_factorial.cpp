#include<stdio.h>

int num,temp=1;

int main()
{
	printf("enter a number: ");
	scanf("%d",&num);
	
	for(int i=1;i<=num;i++)
	{
		temp=temp*i;
	}
	printf("factorial: %d", temp);
}