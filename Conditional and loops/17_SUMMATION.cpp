#include<stdio.h>
int num,temp;
int main()
{
	printf("enter a number of your choice: ");
	scanf("%d",&num);
	
	for(int i=1;i<=num;i++)
	{
		temp=temp+i;
	}
	printf("summation= %d",temp);
}