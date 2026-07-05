#include<stdio.h>

int num1,num2,add,sub,div,mul,rem;

int main()
{
	printf("Enter first number: ");
	scanf("%d",&num1);
	printf("Enter second number: ");
	scanf("%d",&num2);
	
//	add = num1 + num2;
//	sub = num1 - num2;
//	div = num1 / num2;
//	mul = num1 * num2;
	rem = num1 % num2;
	
//	printf("sum: %d",add);
//	printf("diff: %d",sub);
//	printf("quot: %d",div);
//	printf("prod: %d",mul);
	printf("remainder: %d",rem);
}