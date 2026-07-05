#include<stdio.h>
int n1,*n=&n1;
float dec1, add,*d=&dec1,*a=&add;

int main()
{
	printf("enter number1: ");
	scanf("%f",&dec1);
	printf("enter number2: ");
	scanf("%d",&*n);
	
	*a = *d + *n;
	printf("add = %f",*a);
}