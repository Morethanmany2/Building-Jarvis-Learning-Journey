#include<stdio.h>

float add(float dec, int num1, int num2);

float d;
int n1,n2;

int main()
{
	printf("Enter a dec, num1, and num2: ");
	scanf("%f %d %d",&d,&n1,&n2);
	float var = add(d,n1,n2);
	printf("ADD = %f", var);
}

float add(float dec, int num1, int num2)
{
	float a;
	a = dec + num1 + num2;
}
