#include<stdio.h>

void US_dollar(float dollar);
void UK_pound(float pound);
void Dirham(float dirham);
void Yuan(float yuan);

float dollar,pound,dirham,yuan,INR;

int main()
{
    int choice;
    printf("Choice of currency\n1. USA dollar\n2. UK Pound\n3. Dirham\n4. Yuan\n");
    printf("Enter amount in INR: ");
    scanf("%f",&INR);
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: US_dollar(dollar);
        break;

        case 2: UK_pound(pound);
        break;

        case 3: Dirham(dirham);
        break;

        case 4: Yuan(yuan);
        break;
    }
}

void US_dollar(float dollar)
{
    float exchange = 0.0105;
    dollar = INR * exchange ;
    printf("%f INR = %f USD",INR,dollar);
}

void UK_pound(float pound)
{
    float exchange = 0.008;
    pound = INR * exchange ;
    printf("%f INR = %f GBP",INR,pound);
}

void Dirham(float dirham)
{
    float exchange = 0.038;
    dirham = INR * exchange ;
    printf("%f INR = %f AED",INR,dirham);
}

void Yuan(float yuan)
{
    float exchange = 0.07;
    yuan = INR * exchange ;
    printf("%f INR = %f CNY",INR,yuan);
}