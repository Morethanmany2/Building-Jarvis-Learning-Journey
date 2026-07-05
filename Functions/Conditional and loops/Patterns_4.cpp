#include<stdio.h>
void printPattern(int n);
int main(){
    int n=12;
    printPattern(n);
}

void printPattern(int n){
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=i;j++){
            if(j%2!=0){
                printf("%d",j);
            }
        }
        printf("\n");
    }
}