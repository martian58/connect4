#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

// ANSI color codes
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int CompTurn();
int gravity(int col);
int checkWinner(int row, int col);

int CompTurn()
{
    srand(time(NULL));
    int col;


    for (col = 0; col < COLS; col++)
    {
        int row = gravity(col);
        if (row != -1)
        {

            board[row][col] = '*';
            if (checkWinner(row, col) == 1)
            {
                board[row][col] = ' ';
                return col;
            }
            board[row][col] = ' ';
        }
    }

    for (col = 0; col < COLS; col++)
    {
        int row = gravity(col);
        if (row != -1)
        {

            board[row][col] = 'o';
            if (checkWinner(row, col) == 1)
            {

                board[row][col] = ' ';
                return col;
            }
            board[row][col] = ' ';
        }
    }

    // If no winning or blocking moves, make a random move
    return rand() % COLS;
}

int checkWinner(int row, int col)
{

    char piece = board[row][col];
    int count = 0;

    // Check horizontal
    for (int j = 0; j < COLS; j++)
    {
        if (board[row][j] == piece)
        {
            count++;
            if (count == 4)
                return 1;
        }
        else
        {
            count = 0;
        }
    }

    // Check vertical
    count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][col] == piece)
        {
            count++;
            if (count == 4)
                return 1;
        }
        else
        {
            count = 0;
        }
    }

    // Check diagonally (bottom-left to top-right)
    count = 0;
    int start_row = row, start_col = col;
    while (start_row > 0 && start_col > 0)
    {
        start_row--;
        start_col--;
    }
    while (start_row < ROWS && start_col < COLS)
    {
        if (board[start_row][start_col] == piece)
        {
            count++;

            if (count == 4)
                return 1;
        }
        else
        {
            count = 0;
        }
        start_row++;
        start_col++;
    }

    // Check diagonally (top-left to bottom-right)
    count = 0;
    start_row = row;
    start_col = col;
    while (start_row > 0 && start_col < COLS - 1)
    {
        start_row--;
        start_col++;
    }
    while (start_row < ROWS && start_col >= 0)
    {
        if (board[start_row][start_col] == piece)
        {
            count++;
            if (count == 4)
                return 1;
        }
        else
        {
            count = 0;
        }
        start_row++;
        start_col--;
    }

    return 0;
}

int gravity(int col)
{
    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][col] == ' ')
            return i;
    }
    return -1;
}

int checkThecell(int row, int col)
{
    if (board[row][col] == ' ')
        return 0;
    else if (board[row][col] == '*')
        return 1;
    else if (board[row][col] == 'o')
        return -1;
    return 0;
}

void initialize_board()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void display_board()
{
    printf("\n  1   2   3   4   5   6   7\n");
    printf("+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == '*')
                printf("| " RED "*" RESET " ");
            else if (board[i][j] == 'o')
                printf("| " YELLOW "o" RESET " ");
            else
                printf("|   ");
        }
        printf("|\n");
        printf("+---+---+---+---+---+---+---+\n");
    }
}

int CompOrUser()
{
    char opponent;

    printf("Would you like to play against a Bot or a User? (B/U): ");
    scanf(" %c", &opponent);
    if (opponent == 'B')
        return 0;
    else if (opponent == 'U')
        return 1;
    else
    {
        printf("Invalid input. Try again.\n");
        return CompOrUser();
    }
}

int main()
{

    int turn = 0;
    initialize_board();
    display_board();

    if (CompOrUser() != 0)
    {
        // With user
        while (1)
        {
            int col;
            if (turn == 0)
                printf("Yellow(o) is playing.\n");
            else
                printf("Red(*) is playing.\n");

            printf("Enter column (1-7): ");
            scanf("%d", &col);
            col = col - 1;

            int row = gravity(col);

            while (row == -1)
            {
                printf("Column full. Try again: ");
                scanf("%d", &col);
                col = col - 1;
                row = gravity(col);
            }

            board[row][col] = (turn == 0) ? 'o' : '*';
            display_board();

            if (checkWinner(row, col) == 1)
            {
                if (turn == 0)
                    printf(YELLOW "Yellow(o) wins!\n" RESET);
                else
                    printf(RED "Red(*) wins!\n" RESET);
                break;
            }
            turn = (turn + 1) % 2;
        }
    }
    else
    {
        // With computer
        while (1)
        {
            int col;

            if (turn == 0)
            {
                printf("User is playing.\n");
                printf("Enter column (1-7): ");
                scanf("%d", &col);
                col = col - 1;
            }
            else
            {
                printf("Computer is playing.\n");
                col = CompTurn();
            }

            int row = gravity(col);

            while (row == -1)
            {
                if (turn == 0)
                {
                    printf("Column full. Try again: ");
                    scanf("%d", &col);
                }
                col = (turn == 0) ? col - 1 : CompTurn();
                row = gravity(col);
            }

            board[row][col] = (turn == 0) ? 'o' : '*';
            display_board();

            if (checkWinner(row, col) == 1)
            {
                if (turn == 0)
                    printf(YELLOW "User wins!\n" RESET);
                else
                    printf(RED "Computer wins!\n" RESET);
                break;
            }
            turn = (turn + 1) % 2;
        }
    }
    return 0;
}
