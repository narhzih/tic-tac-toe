#include <stdio.h>

void displayBoard(char board[3][3]);

int main() {
    int player = 0;
    int winner = 0;
    int choice = 0;
    int row = 0;
    int column = 0;
    int line = 0;

    char board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
    };
    for (int i =0; i < 9 && winner==0; i++) {
        displayBoard(board);
        player = i%2 + 1;
        do {
            printf("\n Player %d please select the square number to insert your %c: ",
                   player, (player==1)? 'X': 'O');
            scanf("%d", &choice);

            row = --choice/3;
            column = choice%3;
        }while(choice < 0 || choice > 9 || board[row][column] > '9');
        board[row][column] = (player==1)? 'X': 'O';

        // Check for winner on the diagonals first;
        if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
           (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
            winner = player;
        else
            for (line = 0; line <= 2 ; line++)
                if ((board[line][0] == board[line][1] && board[line][0] == board[line][2]) ||
                    (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                    winner = player;
    }

    displayBoard(board);
    if (winner == 0)
        printf("The game is a tie, how boring??");
    else
        printf("\n Congratulations player %d, YOU'RE THE WINNER!!!", winner);


    return 0;
}


void displayBoard(char board[3][3]) {
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}