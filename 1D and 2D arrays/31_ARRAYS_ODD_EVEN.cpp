#include<stdio.h>

int jarvis[100],size,i;
int main()
{
	printf("Enter a size for array[i]: ");
	scanf("%d",&size);
	for(i=0;i<=size;i++)
	{
		printf("enter elements[%d]: ",i);
		scanf("%d",&jarvis[i]);
	}
	for(i=0;i<=size;i++)
	{
		if(jarvis[i]%2==0)
		{
			printf("even number:%d\n",jarvis[i]);
		}
		else
		{
			printf("odd numbers:%d\n",jarvis[i]);
		}
	}
}