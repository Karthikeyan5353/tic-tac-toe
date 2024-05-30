#include <stdio.h>

// Function prototypes
void drawBoard(char board[3][3]);
int checkWin(char board[3][3]);
void playerMove(char board[3][3], char player);

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int turn = 0;
    char player;

    while (1) {
        drawBoard(board);
        player = (turn % 2 == 0) ? 'X' : 'O';
        printf("Player %c, enter your move (1-9): ", player);
        playerMove(board, player);
        turn++;

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }

        if (turn == 9) {
            drawBoard(board);
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

// Function to draw the current state of the board
void drawBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if there is a winner
int checkWin(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

// Function to handle player move
void playerMove(char board[3][3], char player) {
    int move;
    int validMove = 0;

    while (!validMove) {
        scanf("%d", &move);
        move--; // Adjust for 0-indexed array

        int row = move / 3;
        int col = move % 3;

        if (move >= 0 && move < 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            validMove = 1;
        } else {
            printf("Invalid move, try again: ");
        }
    }
}
