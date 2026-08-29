#include<stdio.h>

int main()
{
	int n1,n2;
	
	printf("enter num1= ");
	scanf("%d",&n1);
	printf("enter num2= ");
	scanf("%d",&n2);
	
	int rem;
	while(n2!=0)
	{
		rem=n1%n2;
		n1=n2;
		n2=rem;
	}
	printf("GCD:%d",n1);
}