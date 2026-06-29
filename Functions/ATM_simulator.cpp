#include<stdio.h>

int pin_verification(int pin);
void balance_inquiry(double balance);
void deposit(double amount);
void withdraw(double amount);
void transaction_history(double history[], int size);

int pin = 1234;
double balance = 1000.0;
int main(){

    int size = 10;
    double amount, history[10];
    int choice;
    printf("Welcome to the ATM Simulator!\nATM menu:\n1. Balance Inquiry\n2. Deposit\n3. Withdraw\n4. Transaction History\n");
    printf("Please enter your choice:");
    scanf("%d", &choice);
    switch(choice){
        
        case 1:
            if(pin_verification(pin)){
                balance_inquiry(balance);
            }
            break;

        case 2:
            if(pin_verification(pin)){
                deposit(amount);
            }
            break;

        case 3:
            if(pin_verification(pin)){
                withdraw(amount);
            }
            break;

        case 4:
            if(pin_verification(pin)){
                transaction_history(history, size);
            }
            break; 
    }
}

int pin_verification(int pin){
    printf("Enter your secret PIN: ");
    scanf("%d",&pin);
    if(pin==1234){
        printf("PIN verification successful!\n");
        return 1;
    }
    else{
        printf("Incorrect PIN. Please try again.\n");
        return 0;
    }
}

void balance_inquiry(double balance){
    if(pin==1234){
        printf("Your current balance is: $%.2f\n", balance);
    }
    else{
        printf("Incorrect PIN. Please try again.\n");
    }
}

void deposit(double amount){
    double sum;
    if(pin==1234){
        printf("Enter the amount to deposit: ");
        scanf("%lf",&amount);
        sum=balance+amount;
        printf("Deposit successful! Your new balance is: $%.2f\n", sum);
    }else{
        printf("Incorrect PIN. Please try again.\n");
    }
}

void withdraw(double amount){
    if(pin==1234){
        printf("Enter the amount to withdraw: ");
        scanf("%lf",&amount);
    }else{
        printf("Incorrect PIN. Please try again.\n");
    }
    if(amount>balance){
        printf("Insufficient funds. Your current balance is: $%.2f\n", balance);
    }
    else{
        balance-=amount;
        printf("Withdrawal successful! Your new balance is: $%.2f\n", balance);
    }
}

void transaction_history(double history[], int size){
    if(pin==1234){
        printf("Transaction History:\n");
        for(int i=0;i<size;i++){
            printf("$%.2f\n", history[i]);
        }
    }else{
        printf("Incorrect PIN. Please try again.\n");
    }
}