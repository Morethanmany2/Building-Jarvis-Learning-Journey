#include<stdio.h>
#include<string.h>

char a[20],b[20],len1,len2;

int main()
{
	printf("enter a: ");
	scanf(" %s",&a);
	printf("enter b: ");
	scanf(" %s",&b);
	
//	strlwr(a);
//	printf("lower case: %s",a);
//	strupr(b);
//	printf("upper case: %s",b);

//	len1 = strlen(a);
//	printf("%d",len1);
//	len2 = strlen(b);
//	printf("%d",len2);
	
//	strcat(a,b);
//	printf("concatination is %s",a);

//	strcpy(a,b);
//	printf("a: %s",a);

//	strrev(a);
//	printf("reversed string is %s",a);

	if(strcmp(a,b)==0)
	{
		printf("same string");
	}
	else
	{
		printf("different strings");
	}
}