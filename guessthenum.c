#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define BOLD_ON "\x1b[1m"
#define ANSI_COLOR_RESET "\x1b[0m"

// write the user part of the project

int CompTurn(int minvalue, int maxvalue)
{
    if (minvalue == maxvalue)
        return minvalue;
    int maxrange = rand() % (maxvalue - minvalue) + minvalue;
    return maxrange;
}

int main()
{

    srand(time(NULL));
    int tries;
    int userinput;
    int minvalue = 1;
    int maxvalue = 999;
    char check;
    char answer;
    int temp;

    printf(ANSI_COLOR_MAGENTA BOLD_ON "       WELCOME TO GUESS THE NUMBER GAME!       " ANSI_COLOR_RESET "\n");
    printf("Would you like to guess a number and let computer find it? [y/n]\n");
    scanf(" %c", &answer);
    if ((answer == 'y'))
    {
        printf("Ok, let's play!\n");

        printf("Enter a number between 1 and 999: ");
        scanf("%d", &userinput);
        while (userinput > 999 || userinput < 1)
        {
            printf("Invalid number\n");
            printf("Try again...\n");
            printf("Enter a number between 1 and 999: ");
            scanf("%d", &userinput);
        }
        while ((temp = CompTurn(minvalue, maxvalue)) != userinput)
        {
            tries++;
            printf("Is the number: %d?[y/n]", temp);
            scanf(" %c", &answer);
            if (answer == 'y')
            {
                printf("Computer guessed the number!\n");
                break;
            }
            printf("g if comp>user s if comp<user\nEnter [g/s]?\n ");
            scanf(" %c", &check);
            if ((check == 'g') || (check == 'G'))
            { // userinput>CompTurn
                printf("Computer tries again...\n");

                maxvalue = temp - 1;
            }
            else if ((check == 's') || (check == 'S'))
            { // userinput<CompTurn
                printf("Computer tries again...\n");

                minvalue = temp + 1;
            }

            printf("%d, ", minvalue);
            printf("%d\n", maxvalue);
        }
        printf(ANSI_COLOR_RED "Computer found your number!\n" ANSI_COLOR_RESET "Which is: %d.\nIt took %d tries.\n" ANSI_COLOR_GREEN "It guessed it in %d tries!\n" ANSI_COLOR_RESET, temp, tries);
    }
    else if ((answer == 'n'))
    {
        printf("Ok, so let's make computer choose a number\n");
        temp = CompTurn(minvalue, maxvalue);
        printf(ANSI_COLOR_CYAN "Computer guessed the number!\n" ANSI_COLOR_RESET);
        printf("Try to find it:)\n");

        int userinput;
        int tries = 0;
        while (temp != userinput)
        {
            printf("Enter your guess: ");
            tries++;
            scanf("%d", &userinput);
            if (temp > userinput)
            {
                printf("Try higher\n");
            }
            else if (temp < userinput)
            {
                printf("Try lower\n");
            }
        }
        printf(ANSI_COLOR_RED "You found computer's guess!\n" ANSI_COLOR_RESET "Which is: %d.\n" ANSI_COLOR_GREEN "you guessed it in %d tries!\n" ANSI_COLOR_RESET, temp, tries);
    }

    return 0;
}