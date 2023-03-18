#include <stdio.h>
#include <stdbool.h>

void main()
{

    char *boardDisplay[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
    int boardCalc[3][3] = {{12,13,14},{15,16,17},{18,19,20}};
    int moves[9] = {0,0,0,0,0,0,0,0,0};
    int turncount = 0;
    int turn = 1;
    int input;

    void makeBoard()
    {
        printf("\e[1;1H\e[2J\n  %s  |  %s  |  %s  \n-----------------\n", boardDisplay[0][0], boardDisplay[0][1], boardDisplay[0][2]);
        printf("  %s  |  %s  |  %s  \n-----------------\n", boardDisplay[1][0], boardDisplay[1][1], boardDisplay[1][2]);
        printf("  %s  |  %s  |  %s  \n", boardDisplay[2][0], boardDisplay[2][1], boardDisplay[2][2]);
    }

    void printInstructions()
    {
        printf("\e[1;1H\e[2J\n\n\e[4mGUIDE\e[0m\n\n");
        printf("Just Give me the number of box to tic or tac.I will do it and show the board for you. Enjoy The game! \n\n");
        printf("  1  |  2  |  3  \n-----------------\n");
        printf("  4  |  5  |  6  \n-----------------\n");
        printf("  7  |  8  |  9  \n\n\n\n");
    }
    int checkInputValid(int inp)
    {
        //printf("\nTaken moves: ");
        for (int i = 0; i < 9; i++)
        {
            //printf("%d,",moves[i]);
            if (moves[i] == inp)
            {
                return 0;
            }
        }
        if (inp < 0 || inp > 10)
        {
            return 0;
        }
        return 1;
    }
    void playOneTurn()
    {
        printf("Player %s, Enter Your move [1-9]: ",(turn == 1) ? "X" : "O");
        scanf("%d", &input);
        //printf("\nCurrent turn: %d\n",turncount);
        if (checkInputValid(input) == 0)
        {
            printf("\nEnter a valid option or already taken!!!\n\n");
        }
        else
        {
            moves[turncount] = input;
            input -= 1;
            boardDisplay[(int)(input / 3)][input % 3] = (turn == 1) ? "X" : "O";
            boardCalc[(int)(input / 3)][input % 3] = turn;
            turncount++;
            if (turn == 1)
            {
                turn = 0;
            }
            else
            {
                turn = 1;
            }
        }
    }

    int isGameOver(){
        for (int i = 0; i < 3; i++)
        {
            if (boardCalc[i][0] == boardCalc[i][1] && boardCalc[i][1]  == boardCalc[i][2])
            {
                boardDisplay[i][0] = "$";
                boardDisplay[i][1] = "$";
                boardDisplay[i][2] = "$";
                makeBoard();
                printf("\n\nPlayer %s won the game\n\n",(boardCalc[i][0] == 1) ? "X" : "O");
                return 1;
            }
        }

        for (int j = 0; j < 3; j++)
        {
            if (boardCalc[0][j] == boardCalc[1][j] && boardCalc[1][j] == boardCalc[2][j])
            {
                boardDisplay[0][j] = "$";
                boardDisplay[1][j] = "$";
                boardDisplay[2][j] = "$";
                makeBoard();
                printf("\n\nPlayer %s won the game\n\n",(boardCalc[0][j] == 1) ? "X" : "O");
                return 1;
            }
        }
        
        
        return 0;
        
    }

    // makeBoard();
    printInstructions();
    while (true)
    {
        if (turncount < 9 && isGameOver() == 0)
        {
            playOneTurn();
            makeBoard();
        }
        else
        {
            break;
        }
    }
    printf("\n\nGame Over\n\n");
}