#include<stdio.h>

int num;
float f;
char c;

int main()
{
	printf("Enter an integer: ");
	scanf("%d", &num);
	printf("Enter a decimal: ");
	scanf("%f", &f);
	printf("Enter a charachter: ");
	scanf(" %c", &c);
	
	printf("integer:%d \n",num);
	printf("decimal:%f \n",f);
	printf("charachter:%c ",c);
	
}