#include<stdio.h>
void printPattern(int n);
int main(){
    int n;
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    printPattern(n);
}
void printPattern(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
}