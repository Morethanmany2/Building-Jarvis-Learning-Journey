#include<stdio.h>

void deposit(float *balance);
void withdraw(float *balance);
void check_balance(float balance);

int choice;
int main()
{
    float current_balance = 1000.00;
    printf("Welcome to bank portal, Please enter your choice \n");
    printf("1. Deposit\n2. Withdrawl \n3. Check balance\n\n");
    printf("Choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1: deposit(&current_balance);
        break;

        case 2: withdraw(&current_balance);
        break;

        case 3: check_balance(current_balance);
        break;

        default:
        printf("Invalid choice!\n");
    }
    return 0;
}

void deposit(float *balance)
{
    float income;
    printf("enter the amount to be deposited: ");
    scanf("%f",&income);
    *balance += income;
    printf("%.2f INR deposited in your account",*balance);
}

void withdraw(float *balance)
{
    float outcome;
    printf("enter the amount to be withdrawn: ");
    scanf("%f",&outcome);
    if(outcome<=*balance)
    {
        *balance -= outcome;
        printf("Amount withdrawal succesfull. Current balance is %.2f INR", *balance);
    }
    else{
        printf("insufficient funds!");
    }
    
}

void check_balance(float balance)
{
    printf("Your account balance is %.2f INR",balance);
}