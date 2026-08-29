#include<stdio.h>
int start=0, end=10;
int main()
{
	do
	{
		printf("%d\n", start);
		start++;
	}
	while(start<=end);
	
/*	while(start<=end)
	{
		printf("%d\n", start);
		start ++;
	}*/
}