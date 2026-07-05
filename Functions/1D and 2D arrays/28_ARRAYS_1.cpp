#include<stdio.h>

char panasonic[5];

int count;
int main()
{
	for(count=0; count<5;count++)
	{
		
		printf("enter an array: ");
		scanf(" %c",&panasonic[count]);
	}
	
	for(count=0; count<5;count++)
	{
		
		printf("Array elements: %c", panasonic[count]);
	}
}