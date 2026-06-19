#include<stdio.h>

int num=10;
int *p=&num;
int **q=&p,***r=&q;

int main()
{
	printf("Num= %d\n",num);
	printf("num using pointer= %d\n",*p);
	printf("double pointers=%d\n",**q);
	printf("triple pointers=%d\n",***r);
	printf("address of num=%d\n",p);
	printf("value inside pointer=%d\n",p);
	printf("pointer expnaded =%d\n",*(&num));
	printf("pointer address=%d\n",&p);
}