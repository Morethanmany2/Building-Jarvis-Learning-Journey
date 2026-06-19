#include<stdio.h>

int jarvis[100],size,i,sum;
int main()
{
	printf("Enter a size for array[i]: ");
	scanf("%d",&size);
	for(i=0;i<=size;i++)
	{
		printf("enter elements[%d]: ",i);
		scanf("%d",&jarvis[i]);
	}
	for(i=0; i<=size;i++)
	{
		sum += jarvis[i];
	}

	printf("summation: %d",sum);
}