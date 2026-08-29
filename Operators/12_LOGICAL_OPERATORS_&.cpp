#include<stdio.h>

char alpha;
int main()
{
	printf("enter a charachter: ");
	scanf(" %c", &alpha);
	
	if(alpha >= 'A' && alpha <= 'Z')
	{
		printf("it is a capital alphabet");
	}
	else if(alpha >= 'a' && alpha <= 'z')
	{
		printf("it is a small alphabet");
	}
	else if(alpha >= '0' && alpha <= '9')
	{
		printf("it is a number");
	}
	else
	{
		printf("it is a special charachter");
	}
} 