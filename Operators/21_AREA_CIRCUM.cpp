#include<stdio.h>
float r,pi=3.14,area,circumference;

int main()
{
	printf("enter a radius of circle: ");
	scanf("%f",&r);
	area = pi*r*r;
	circumference = 2*pi*r;
	printf("area = %f\n",area);
	printf("circumference = %f",circumference);
}