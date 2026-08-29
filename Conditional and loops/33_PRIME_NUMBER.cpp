#include<stdio.h>

int main()
{
	int num,prime=1;
	printf("Enter a number: ");
	scanf("%d",&num);
	if(num==0 || num==1)
	{
		printf("%d not a prime nor composite",num);
	}
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			prime=0;
			break;
		}
	}
	if(prime)
	{
		printf("%d is a prime",num);
	}
	else
	{
		printf("%d is not a prime",num);
	}
}