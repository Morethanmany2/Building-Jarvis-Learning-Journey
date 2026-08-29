#include<stdio.h>

int main()
{
	int num,i;
	printf("enter a number: ");
	scanf("%d",&num);
	
	for(i=1;i<=num;i++)
	{
		int rem=num%i;
		if(rem!=0)
		{
			continue;
		}
		else
		{
			printf("%d,",i);
		}
	}
}