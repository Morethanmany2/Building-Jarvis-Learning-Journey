#include<stdio.h>

int num1,num2;

int main()
{
	printf("Enter first number: ");
	scanf("%d",&num1);
	printf("Enter second number: ");
	scanf("%d",&num2);
	
	num1 += num2;
//	num1 -= num2;
//	num1 /= num2;
//	num1 *= num2;
//	num1 %= num2;
	
	printf("result: %d",num1);
	
}