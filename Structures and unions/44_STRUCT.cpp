#include<stdio.h>


int main()
{
	struct aditya{
	int num;
	char ch;
	float dec;
	int num1;
}; 
	struct aditya a1;
	
	printf("Enter a dec: ");
	scanf("%f",&a1.dec);
	printf("Enter a num: ");
	scanf("%d",&a1.num);
	printf("Enter a char: ");
	scanf(" %c",&a1.ch);
	printf("Enter a num1: ");
	scanf("%d",&a1.num1);
	
	printf("dec: %f\n",a1.dec);
	printf("num: %d\n",a1.num);
	printf("num1: %d\n",a1.num1);
	printf("char: %c",a1.ch);
	
}