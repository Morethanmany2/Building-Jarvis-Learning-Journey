#include<stdio.h>

void gcd();
void lcm();
int n1,n2,GCD,a,b;

int main()
{
	printf("Enter a number: ");
	scanf("%d",&n1);
	printf("enter a number: ");
	scanf("%d",&n2);
	a=n1;
	b=n2;
	gcd();	
	lcm();
}
void gcd()
{
	int rem;
	while(n2!=0)
	{
		rem=n1%n2;
		n1=n2;
		n2=rem;
	}
	GCD=n1;
}

void lcm()
{
	int LCM = (a*b)/GCD;
	printf("LCM:%d",LCM);
}