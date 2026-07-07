#include<stdio.h>
#include<string.h>
void menu(int choice);
void add_book();
void view_book();


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
        char phone[11];
        int issued;
    };
    struct member m1;

int main(){
    int choice;
    while(1){
        printf("WELCOME TO LIBRARY MANAGEMENT\n");
        printf("MENU\n1.Add a book\n2.View books\n3.Register Member\n4.Issue Book\n5.Return Book\n");
        printf("please enter your choice: ");
        scanf("%d",&choice);
        menu(choice);

    }
    
    
}

void menu(int choice){

    switch(choice){
        case 1:
        add_book();
        break;

        case 2:
        view_book();
        break;

        case 3:
        break;

        default:
        printf("enter your choice");
    }
}

void add_book(){
    printf("Enter the book id: ");
    scanf("%d",&b1.book_id);
    printf("Enter book name: ");
    scanf("%s",&b1.book_name);
    printf("Enter author name: ");
    scanf("%s",&b1.author);
    printf("Enter available copies: ");
    scanf("%d",&b1.copies_available);
    printf("Book added succesfully\n\n");
}

void view_book()
{
    int book_id;
    printf("Enter the book id: ");
    scanf("%d",&book_id);
    if(book_id == b1.book_id){
        printf("------*-------*------\n");
        printf("Your Book is retrived\n");
        printf("------*-------*------\n");
        printf("Book id:%d \n",b1.book_id);
        printf("Book name:%s \n",b1.book_name);
        printf("Book author:%s \n",b1.author);
        printf("Available copies:%d \n\n",b1.copies_available);
    }
    else{
        printf("Please enter a valid book id!\n\n");
    }
}