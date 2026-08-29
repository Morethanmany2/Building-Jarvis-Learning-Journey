#include<stdio.h>
int sunfit[3][2]={{1,2},{3,4},{5,6}};

int rows,cols;
int main()
{
	for(rows=0;rows<3;rows++)
	{
		for(cols=0;cols<2;cols++)
		{
			printf("%d\t",sunfit[rows][cols]);
		}
		printf("\n");
	}
}