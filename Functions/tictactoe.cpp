#include <stdio.h>
void initialize(char board[3][3]);
void switch_player();
void display(char board[3][3]);
int space_check(int row, int col);
int check_winner(char currentPlayer);

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';
int row = 0;
int col = 0;

int main() {
    initialize(board);
        while(1){
            printf("Player %c's turn\n",currentPlayer);
            printf("Enter row & column: ");
            scanf("%d %d", &row, &col);
            if(space_check(row,col)){
                board[row][col] = currentPlayer;
                display(board);
                if(!check_winner(currentPlayer)){
                   switch_player();
                }else{
                    break;
                }
                    
            }
            
            
            
            // printf("Player %c's turn\n",currentPlayer);
            // store_display();
            // space_check();
            // display(board);

        }
}

// initialize function
void initialize(char board[3][3]){
    printf("Current board:\n");
    for(int i=0;i<3;i++){
            printf(" %c | %c | %c", board[i][0], board[i][1], board[i][2]);
        if(i<2){
            printf("\n---+---+---\n");
        }
    }
}

// display function
void display(char board[3][3]){
    printf("Current board:\n");
    for(int i=0;i<3;i++){
            printf(" %c | %c | %c", board[i][0], board[i][1], board[i][2]);
        if(i<2){
            printf("\n---+---+---\n");
        }
    }
}



// switch function
void switch_player(){
    if(currentPlayer == 'X'){
        currentPlayer ='O';
    }
    else{
        currentPlayer = 'X';
    }
}


// space checker
int space_check(int row, int col){
    if(board[row][col] == ' '){
        printf("%c",currentPlayer);
        return 1;
    }
    else{
        printf("space is occupued! Try again");
        return 0;
    }

}

// winner decision
int check_winner(char currentPlayer){
    for(int i=0;i<=2;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                if(board[i][0] != ' ' && board[i][1] != ' ' && board[i][2] != ' '){
                printf("winner is %c",currentPlayer);
                return 1;
            }
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] != ' ' && board[1][i] != ' ' && board[2][i] != ' '){
                printf("winner is %c",currentPlayer);
                return 1;
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
                if(board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' '){
                printf("winner is %c",currentPlayer);
                return 1;
            }
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
                if(board[0][2] != ' ' && board[1][1] != ' ' && board[2][0] != ' '){
                printf("winner is %c",currentPlayer);
                return 1;
            }
        }
    }
    return 0;
}