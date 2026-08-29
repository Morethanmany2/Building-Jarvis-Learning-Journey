#include<stdio.h>
int num,temp;
int main()
{
	printf("Enter a start number: ");
	scanf("%d", &num);

	
	for(int j=1; j<=10; j++)
	{
		temp=num*j;
		printf("%d * %d = %d\n",num,j,temp);
	}
}