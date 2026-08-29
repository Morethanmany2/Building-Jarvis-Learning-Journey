#include<stdio.h>


int main()
{
	union aditya{
	int num;
	char ch;
	float dec;
	int num1;
};
	union aditya a1;
	
	
	printf("Enter a num: ");
	scanf("%d",&a1.num);
	printf("Enter a char: ");
	scanf(" %c",&a1.ch);
	printf("Enter a num1: ");
	scanf("%d",&a1.num1);
	printf("Enter a dec: ");
	scanf("%f",&a1.dec);
	
	printf("dec: %f\n",a1.dec);
	printf("num: %d\n",a1.num);
	printf("num1: %d\n",a1.num1);
	printf("char: %c",a1.ch);
	
}