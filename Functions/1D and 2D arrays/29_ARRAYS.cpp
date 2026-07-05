#include<stdio.h>
int jarvis[100],s;

int main()
{
	printf("Enter the size of array: ");
	scanf("%d",&s);
	jarvis[s];
	for(int i=0;i<=s;i++)
	{
		printf("enter an element[i]: ");
		scanf("%d",&jarvis[i]);
	}
	for(int i=0;i<=s;i++)
	{
		printf("%d is in jarvis\n",jarvis[i]);
	}
}