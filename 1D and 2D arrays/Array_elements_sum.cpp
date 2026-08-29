#include<stdio.h>
void sum_even_array();
void sum_odd_array();
int arr[3]={1,2,3};


void sum_even_array()
{
	int even=0;
	for(int i=0;i<3;i++)
	{
		if(arr[i]%2==0)
		{
			even+=arr[i];
		}
	}
	printf("sum of even:%d\n",even);
}

void sum_odd_array()
{
	int odd=0;
	for(int i=0;i<3;i++)
	{
		if(arr[i]%2!=0)
		{
			odd+=arr[i];
		}
	}
	printf("sum of odd:%d",odd);
}
int main()
{
	sum_even_array();

	sum_odd_array();

}
