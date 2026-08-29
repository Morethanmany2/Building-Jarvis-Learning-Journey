#include<stdio.h>
int num1,num2,num3;

int main()
{
	printf("enter 1st no: ");
	scanf("%d",&num1);
	printf("enter 2st no: ");
	scanf("%d",&num2);
	printf("enter 3rd no: ");
	scanf("%d",&num3);
	
	if(num1 > num2)
	{
		if(num1>num3)
		{
			printf("Largest number = %d",num1);
		}
		else
		{
			printf("Largest number = %d",num3);
			
		}
	}
	else
	{
		if(num2>num3)
		{
			printf("Largest number = %d",num2);
		}
		else
		{
			printf("Largest number = %d",num3);
			
		}
		
	}
}