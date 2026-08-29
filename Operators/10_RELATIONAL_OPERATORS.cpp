#include<stdio.h>

int num;
int main()
{
	printf("Enter A number: ");
	scanf("%d",&num);
	
	if(num%2==0)
	{
		printf("even number");
	}
	else if(num%2==1)
	{
		printf("odd number");
	}
	else
	{
		printf("wrong input");
	}
	
}