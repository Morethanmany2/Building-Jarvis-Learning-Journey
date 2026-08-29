#include<stdio.h>

int num;
int main()
{
	printf("enter a case number: ");
	scanf("%d", &num);
	
	switch(num)
	{
		case 1: printf("Hello world!");
		break;
		
		case 3: int num1, num2;
				printf("Enter number1: \n");
				scanf("%d",&num1);
				printf("Enter number2: ");
				scanf("%d",&num2);
				num1 += num2;
				printf("Add = %d", num1);
		break;
		
		case 5: int num3;
				printf("Enter a number: ");
				scanf("%d", &num3);
				if(num3 % 2 == 0)
				{
					printf("number is even");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
				}
		break;
		
		default : printf("check the number again");		
	}
}