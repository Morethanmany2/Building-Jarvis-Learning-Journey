#include<stdio.h>
int num;
int main()
{
	printf("enter your choice: ");
	scanf("%d", &num);
	
	switch(num)
	{
		case 1:printf("HELLO WORLD!");
		break;
		
		case 2:printf("start coding...");
		break;
		
		case 3:printf("keep grinding!");
		break;
		
		case 4:printf("focus!");
		break;
		
		default:printf("check you choice again");
	}
}