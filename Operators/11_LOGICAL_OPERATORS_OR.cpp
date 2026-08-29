#include<stdio.h>

char alpha;
int main()
{
	printf("enter an alphabet: ");
	scanf(" %c", &alpha);
	
	if(alpha == 'A' || alpha == 'E' || alpha == 'I' || alpha == 'O' || alpha == 'U')
	{
		printf("it is a vowel");
	}
	else if(alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u')
	{
		printf("it is a vowel");
	}
	else
	{
		printf(" it is a consonant");
	}
}