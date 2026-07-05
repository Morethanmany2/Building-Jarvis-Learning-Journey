#include<stdio.h>

void butcher(int num,float dec);

int num1;float dec1;
int main()
{
	printf("Enter a number and a decimal number: ");
	scanf("%d %f", &num1,&dec1);
	
	butcher(num1,dec1);
}

void butcher(int num, float dec)
{
	float add;
	add = num+dec;
	printf("addition = %f", add);
}