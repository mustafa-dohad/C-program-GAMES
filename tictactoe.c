#include<stdio.h>  // ye sab cheez mein dalta hai //
#include<stdlib.h> // neeche ke saare header files ki i took help from internet to run my game
#include<ctype.h>  //                                                                         //
#include<time.h>   //                                                                        //
// thore se general variables declare kar raha hoon jo ke constant rahenge //
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
// yahan pe we'll call out all the functions taake mere liye asaani ho diff function pe diff kaam karne ki//
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
// yeh iss code ki main body//
int main()
{
    char winner = ' ';
    char reply = ' ';

    do
    {
        winner = ' ';
        reply = ' ';

        resetBoard();

        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf("%c", &reply);
        scanf("%c", &reply);
        reply = toupper(reply);
    } while (reply == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}
// this will reset the board when the game is finished//
void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
// thats are board map//
void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
// this will find whether the game is finished or not//
int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
// this is the player's moving code//
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}
// random computer move//
void computerMove()
{
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}
// for winner checking//
char checkWinner()
{
    // yeh check karega rows ko //
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // similar to that ye check karega columns ko//
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // this will check diagnols //
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}
// agar 3 rows || 3 columns || 3 'X' on diagnols are present or if there is no empty spaces left//
void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("\nYOU WIN!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("\nYOU LOSE!\n");
    }
    else
    {
        printf("\nIT'S A TIE!\n");
    }
}
// short and simple magar very affective and efficient code :] //
// also formatted the document so that the code looks clean, organized and easy to understand without excess line of code ✌🏼 //
// i have taken some help from the internet for a few questions i had for example the computer's move and randomizing is header files also before this project my understanding on functions was weak so that too got some help//
// but not anymore i think i have learned so much from making this project //