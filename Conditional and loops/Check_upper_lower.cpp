#include<stdio.h>
void check_case(char c);

int main(){
    char c;
    printf("Program Started\n");
    printf("Enter a character: ");
    scanf("%c", &c);
    check_case(c);
    return 0;
}

void check_case(char c){
    
    if(c >= 'A' && c <= 'Z'){
        printf("%c is an uppercase letter.\n", c);
    }
    else if(c >= 'a' && c <= 'z'){
        printf("%c is a lowercase letter.\n", c);
    }
    else{
        printf("%c is not an alphabetic character.\n", c);
    }
}
