#include<stdio.h>
void ryan_football(); 		//declare function(nonreturn,without parameters)

int main()
{
	printf("This is inside main function: ");
	ryan_football();
	printf("Again we are back inside main function: ");
	ryan_football();
}

void ryan_football()
{
	int num;
	printf("enter a number: ");
	scanf("%d",&num);
	
	if (num%2==1)
	{
		printf("odd number\n");
	}
	else
	{
		printf("even number\n");
	}
}