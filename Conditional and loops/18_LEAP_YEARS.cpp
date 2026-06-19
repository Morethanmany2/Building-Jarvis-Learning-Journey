#include<stdio.h>
int main()
{
	for(int i=2000; i<=2030; i++)
	{
		if(i%4==0)
		{
			printf("Leap years are: %d\n", i);
		}
	}

}