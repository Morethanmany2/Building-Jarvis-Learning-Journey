#include<stdio.h>
int i,j,k;
int main()
{
	for(i=0;i<=1;i++)
	{
		for(j=1;j<=3;j++)
		{
			for(k=1;k<=5;k++)
			{
				printf("%d %d %d\n",i,j,k);
			}
		}
	}
}