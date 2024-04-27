// Connect4 game in C
//edited version
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROWS 6
#define COLS 7
// horizontal; vertical; diagonal check for win (add for each: yellow&red)
// bot
// advanced bot

char board[ROWS][COLS];
int checkWinner(int row, int col)
{
    // check horizontal
    char piece = board[row][col];
    int count = 0;
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
// check vertical
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
    // check diagonally bottom-left to top-right
    count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if(board[i][col]==piece){
            count++;
            col++;
            if(count==4){
                return 1;
            }
        }
        else if(i!=piece){
            count=0;
        }
    }
    // check diagonally bottom-right to top-left
    count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if(board[i][col]==piece){
            count++;
            col--;
            if(count==4){
                return 1;
            }
        }
        else if(i!=piece){
            count=0;
        }
    }
}
int gravity(int col)
{
    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (board[i][col] == ' ')
        {
            return i;
        }
        // else
        // {
        //     return -1;
        // }
    }
}
int checkThecell(int row, int col) // empty=0; red*=1; yellow'o'=-1
{
    // int row = gravity(col);
    if (board[row][col] == ' ')
    {
        return 0;
    }
    else if (board[row][col] = '*')
    {
        return 1;
    }
    else if (board[row][col] == 'o')
    {
        return -1;
    }
}
// int UserRed(int col)
// {
//     int row = gravity(col);

//     printf("Red(*) is playing.\n");
//     printf("Enter col: ");
//     scanf("%d", &col);

//     while (checkThecell(row, col) != 0)
//     {
//         printf("Red(*) tries again.");
//         printf("Enter col: ");
//         scanf("%d", &col);
//     }
//     // show the grid again
//     board[row][col] = '*';
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             printf("%c", board[i][j]);
//         }
//     }
// }
// int UserYellow(int col)
// {
//     int row = gravity(col);
// printf("Yellow(o) is playing.\n");
// printf("Enter col: ");
// scanf("%d", &col);

// while (checkThecell(row, col) != 0)
// {
//     printf("Yellow(o) tries again.");
//     printf("Enter col: ");
//     scanf("%d", &col);
//     // }
//     board[row][col] = 'o';

//     // show the grid again
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             printf("%c", board[i][j]);
//         }
//     }
// }
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
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("+---+---+---+---+---+---+---+\n");
    }
}
int CompOrUser() // 0-> computer ile oyun, 1->user
{
    char opponent;

    printf("Would you like to play against a Bot or a User?(B/U): ");
    scanf("%c", &opponent);
    if (opponent == 'B')
    {
        return 0;
    }
    else if (opponent == 'U')
    {

        return 1;
    }
    else
    {
        printf("Try again.Choose B or U: ");
        scanf("%d", &opponent);
    }
}
int main()
{

    int turn = 0;
    initialize_board();

    display_board();

    // ●	red discs will be represented by (*)
    // ●yellow discs by the lowercase letter o.
    if (CompOrUser() != 0) 
    {
        // user ile oyun

        while (1)
        {
            int col;

            if (turn == 0)
            {
                printf("Yellow(o) is playing.\n");
            }

            else
            {
                printf("Red(*) is playing.\n");
            }

            printf("Enter col: ");
            scanf("%d", &col);
            int row = gravity(col);

            while (checkThecell(row, col) != 0)
            {
                if (turn == 0)
                {
                    printf("Yellow(o) tries again.");
                }

                else
                {
                    printf("Red(*) tries again.");
                }

                printf("Enter col: ");
                scanf("%d", &col);
            }
            if (turn == 0)
            {
                board[row][col] = 'o';
            }

            else
            {
                board[row][col] = '*';
            }

            display_board();

            if (checkWinner(row, col)==1)
            {
                if(turn == 0) printf("User 1 is winner");
                else if(turn == 1) printf("User 2 is winner");

                break;
            }

            turn = (turn + 1) % 2;
        }
    }
    else
    {
        // comp ile oyun
        if (turn == 0)
        {
            // UserYellow(col);
        }
        else
        {
            
            
            // bot
        }
    }
    return 0;
}



// komputerin aptalca oynamasi + dioqanal