#include<stdio.h>
int start,end;
int main()
{
	printf("Enter a start number: ");
	scanf("%d", &start);
	printf("Enter a end number: ");
	scanf("%d", &end);
	
	for(int i=start; i<=end; i++)
	{
		if(i%2==0)
		{
			printf("even numbers: %d\n",i);
		}
		else if(i%2==1)
		{
			printf("odd numbers: %d",i);
		}
	}
}