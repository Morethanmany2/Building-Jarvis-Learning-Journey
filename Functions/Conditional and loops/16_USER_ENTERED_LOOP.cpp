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
		printf("%d\n",i);
	}
}