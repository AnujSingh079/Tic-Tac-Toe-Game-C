#include <stdio.h>

void displayBoard(char board[3][3])
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWinner(char board[3][3])
{
    int i;

    /* Check rows */
    for (i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;

    /* Check columns */
    for (i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;

    /* Check diagonals */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int main(void)
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int choice, row, column;
    int turn = 0, moves = 0, gameOver = 0;
    char player;

    printf("===== TIC-TAC-TOE GAME =====\n");

    while (gameOver == 0 && moves < 9)
    {
        displayBoard(board);

        player = (turn % 2 == 0) ? 'X' : 'O';

        printf("Player %c, enter position (1-9): ", player);

        /* Handle non-numeric input / EOF so the game never loops forever */
        if (scanf("%d", &choice) != 1)
        {
            int ch;
            if (feof(stdin))
                return 0;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            printf("Invalid input! Please enter a number from 1 to 9.\n");
            continue;
        }

        if (choice < 1 || choice > 9)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }

        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (board[row][column] == 'X' || board[row][column] == 'O')
        {
            printf("Position already taken! Try again.\n");
            continue;
        }

        board[row][column] = player;
        moves++;

        if (checkWinner(board))
        {
            displayBoard(board);
            printf("Player %c wins!\n", player);
            gameOver = 1;
        }
        else
        {
            turn++;
        }
    }

    if (gameOver == 0)
    {
        displayBoard(board);
        printf("The game is a draw!\n");
    }

    return 0;
}
