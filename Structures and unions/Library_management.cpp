#include<stdio.h>
#include<string.h>
void menu();
void add_book(struct book b1);

int choice;
struct book{
        int book_id;
        char book_name[50];
        char author[50];
        int copies_available;
    };
    struct book b1;

struct member{
        int member_id;
        char member_name[50];
        char phone[10];
        int issued;
    };
    struct member m1;

int main(){
    printf("WELCOME TO LIBRARY MANAGEMENT\n");
    printf("MENU\n1.Add a book\n2.View books\n3.Register Member\n4.Issue Book\n5.Return Book\n");
    printf("please enter your choice: ");
    scanf("%d",&choice);
    menu();
    
}

void menu(){
    switch(choice){
        case 1:
        add_book(b1);
        break;
        
        case 2:
        break;

        case 3:
        break;

        default:
        printf("enter your choice");
    }
}

void add_book(struct book b1){
    printf("Enter the book id: ");
    scanf("%d",&b1.book_id);
    printf("Enter book name: ");
    scanf("%s",&b1.book_name);
    printf("Enter author name: ");
    scanf("%s",&b1.author);
    printf("Enter available copies: ");
    scanf("%d",&b1.copies_available);
    printf("Book added succesfully");
}