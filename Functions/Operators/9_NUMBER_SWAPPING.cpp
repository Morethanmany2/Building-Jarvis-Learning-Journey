#include<stdio.h>

int num1,num2,temp;
int main()
{
	printf("Enter first number: ");
	scanf("%d",&num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	temp = num1;
	num1 = num2;
	num2 = temp;
	
	printf("first number:%d \n",num1);
	printf("second number:%d ",num2);
}