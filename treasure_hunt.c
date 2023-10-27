#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MULTIPLE 5
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10

int main(void)
{
    // Declare variables
    char player_representation, board[MAX_PATH_LENGTH];
    int lives, path_length, moves, validlives = 0, valid_path_length = 0, validmoves = 0, treasurecount = 0, nextmove, validnextmove = 0;
    int bombs[MAX_PATH_LENGTH], treasure[MAX_PATH_LENGTH];

    // Display game header
    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n\n");

    // Player configuration //
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player_representation);

    // Validate and set the number of lives
    while (!validlives)
    {
        printf("Set the number of lives: ");
        scanf("%d", &lives);
        if (lives >= MIN_LIVES && lives <= MAX_LIVES)
        {
            validlives = 1;
            printf("Player configuration set-up is complete\n\n");
        }
        else
            printf("     Must be between 1 and 10!\n");
    }

    // Game configuration //
    printf("GAME configuration\n");
    printf("------------------\n");

    // Validate and set the path length
    while (!valid_path_length)
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &path_length);
        if ((path_length % MULTIPLE == 0) && (path_length >= MIN_PATH_LENGTH && path_length <= MAX_PATH_LENGTH))
        {
            valid_path_length = 1;
        }
        else
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
    }

    // Initialize the board with dashes
    for (int i = 0; i < path_length; i++)
    {
        board[i] = '-';
    }

    // Validate and set the limit for the number of moves allowed
    while (!validmoves)
    {
        printf("Set the limit for the number of moves allowed: ");
        scanf("%d", &moves);
        if (moves >= 3 && moves <= 15)
        {
            validmoves = 1;
        }
        else
            printf("    Value must be between 3 and 15\n");
    }

    // BOMB Placement
    printf("\nBOMB Placement\n");
    printf("----------------\n");
    printf("Enter the bomb position in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    // Input bomb positions
    int i;
    for (i = 0; i < (path_length / MULTIPLE); i++)
    {
        if (i == 0)
        {
            printf("   Positions [ %d- %d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &bombs[i * 5], &bombs[(i * 5) + 1], &bombs[(i * 5) + 2], &bombs[(i * 5) + 3], &bombs[(i * 5) + 4]);
        }
        else if (i == 1)
        {
            printf("   Positions [ %d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &bombs[i * 5], &bombs[(i * 5) + 1], &bombs[(i * 5) + 2], &bombs[(i * 5) + 3], &bombs[(i * 5) + 4]);
        }
        else
        {
            printf("   Positions [%d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &bombs[i * 5], &bombs[(i * 5) + 1], &bombs[(i * 5) + 2], &bombs[(i * 5) + 3], &bombs[(i * 5) + 4]);
        }
    }
    printf("BOMB placement set\n\n");

    // TREASURE Placement
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    // Input treasure positions
    for (i = 0; i < (path_length / MULTIPLE); i++)
    {
        if (i == 0)
        {
            printf("   Positions [ %d- %d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &treasure[i * 5], &treasure[(i * 5) + 1], &treasure[(i * 5) + 2], &treasure[(i * 5) + 3], &treasure[(i * 5) + 4]);
        }
        else if (i == 1)
        {
            printf("   Positions [ %d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &treasure[i * 5], &treasure[(i * 5) + 1], &treasure[(i * 5) + 2], &treasure[(i * 5) + 3], &treasure[(i * 5) + 4]);
        }
        else
        {
            printf("   Positions [%d-%d]: ", ((i * 5) + 1), ((i * 5) + 5));
            scanf("%d %d %d %d %d", &treasure[i * 5], &treasure[(i * 5) + 1], &treasure[(i * 5) + 2], &treasure[(i * 5) + 3], &treasure[(i * 5) + 4]);
        }
    }
    printf("TREASURE placement set\n\n");

    // Display game configuration
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player_representation);
    printf("   Lives      : %d\n", lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", path_length);
    printf("   Bombs      : ");
    for (i = 0; i < path_length; i++)
    {
        printf("%d", bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < path_length; i++)
    {
        printf("%d", treasure[i]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    // Reset variables for the game loop
    validlives = 0;
    validmoves = 0;

    // Display the initial game board
    printf("  ");
    for (i = 0; i < path_length; i++)
    {
        printf("%c", board[i]);
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= path_length; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", (i / 10));
        }
        else
            printf("|");
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= path_length; i++)
    {
        if (i % 10 == 0)
        {
            printf("0");
        }
        else
            printf("%d", (i % 10));
    }

    // Main game loop
    while (lives > 0 && moves > 0)
    {
        printf("\n+--------------------------------------------------+\n");
        printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d", lives, treasurecount, moves);
        printf("\n+--------------------------------------------------+\n");

        validnextmove = 0;

        // Validate and get the next move from the player
        while (!validnextmove)
        {
            printf("Next Moves [1-%d]: ", path_length);
            scanf("%d", &nextmove);
            if (nextmove < 1 || nextmove > path_length)
            {
                printf("  Out of Range!!!\n");
            }
            else
                validnextmove = 1;
        }
        printf("\n");

        // Process the move
        if (board[nextmove - 1] != '-')
        {
            printf("===============> Dope! You've been here before!\n");
            moves += 1;
        }
        else if (bombs[nextmove - 1] == 1 && treasure[nextmove - 1] == 1)
        {
            board[nextmove - 1] = '&';
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            treasurecount++;
            lives--;
            if (lives == 0)
            {
                printf("\nNo more LIVES remaining!\n");
            }
        }
        else if (bombs[nextmove - 1] == 1)
        {
            board[nextmove - 1] = '!';
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            lives--;
            if (lives == 0)
            {
                printf("\nNo more LIVES remaining!\n");
            }
        }
        else if (treasure[nextmove - 1] == 1)
        {
            board[nextmove - 1] = '$';
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            treasurecount++;
        }
        else if (bombs[nextmove - 1] == 0 && treasure[nextmove - 1] == 0)
        {
            board[nextmove - 1] = '.';
            printf("===============> [.] ...Nothing found here... [.]\n");
        }

        moves--;

        // Display the updated game board
        printf("\n  ");
        for (i = 0; i < path_length; i++)
        {
            if ((i + 1) == nextmove)
            {
                printf("˅");
            }
            else
                printf(" ");
        }
        printf("\n  ");
        for (i = 0; i < path_length; i++)
        {
            printf("%c", board[i]);
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= path_length; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (i / 10));
            }
            else
                printf("|");
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= path_length; i++)
        {
            if (i % 10 == 0)
            {
                printf("0");
            }
            else
                printf("%d", (i % 10));
        }
    }

    // Game over
    printf("\n+--------------------------------------------------+\n");
    printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d", lives, treasurecount, moves);
    printf("\n+--------------------------------------------------+\n");
    printf("\n##################\n");
    printf("#   Game over!   #");
    printf("\n##################\n\n");
    printf("You should play again and try to beat your score!\n\n");
    return 0;
}
