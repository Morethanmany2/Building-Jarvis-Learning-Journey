#include<stdio.h>

float num[4]={1.6,3.8,-6.0,8.1};
float *n=&num[0];

int main()
{
	int count = 0;
	while(count<=3)
	{
		printf("%.1f\n",*n);
		count++;
		*n++;
	}
}