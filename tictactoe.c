// TIC TAC TOE game between 2 players or player vs computer
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

typedef enum { false, true } bool;

struct Board
{
    /* data */
    int turn;
    int attempts;
    char player1Symbol, player2Symbol;

    char topLeft, topMiddle, topRight, left, middle, right, bottomLeft, bottomMiddle, bottomRight;
};

void initializeBoard(struct Board board, int choice);

void printStatus(struct Board board);

bool checkTile(char tile, char choice);

bool checkIfWinner(struct Board board, char currentSymbol);

struct Board tictactoe;

int main(){

    // prompt user for game they wish to play   
    int choice;
    bool typeChoice = false;
    bool winningPlayer = false;
    bool playAgain = true;
    bool invalidInput = false;

    // inits random num generator

    time_t t; 
    srand((unsigned)time(&t)); 

    while(playAgain)
    {

        playAgain = false;

        printf( "===========================\n");
        printf( "WELCOME TO TIC TAC TOE!\n");
        printf( "1 --- person vs. person\n");
        printf( "2 --- person vs. random computer\n");
        printf( "Enter your choice (1 or 2): ");    

        scanf("%i", &choice);     

        // read information from console (only 1 or 2)
        while(!typeChoice)
        {
                typeChoice = true;
                switch (choice)
                {
                case 1:
                    /* code */
                    printf( "===========================\n");
                    printf("You have entered choice 1\n");
                    fflush(stdin);
                    break;
                case 2:
                    printf( "===========================\n");
                    printf("You have entered choice 2\n");
                    fflush(stdin);
                    break;
                default:
                    typeChoice = false;
                    printf("===========================\n");
                    printf("Please enter the correct choice (1 or 2): ");
                    fflush(stdin);
                    scanf("%d", &choice);
                    break;
                }

        }

        // initializing board
        tictactoe.turn = 1;
        tictactoe.player1Symbol = 'X';
        tictactoe.player2Symbol = 'O';

        tictactoe.attempts = 0;

        tictactoe.topLeft = ' ';
        tictactoe.topMiddle = ' ';
        tictactoe.topRight = ' ';
        tictactoe.left = ' ';
        tictactoe.middle = ' ';
        tictactoe.right = ' ';
        tictactoe.bottomLeft = ' ';
        tictactoe.bottomMiddle = ' ';
        tictactoe.bottomRight = ' ';

        winningPlayer = false;

        /*
        * Option 1: player v player
        * Display board, prompt player 1 (X)
        * read info (Format: # #; (1-3), (1-3))
        * Display board with new X, prompt player 2 (O)
        * read info 
        * keep alternating between player 1 or 2 while
        * checking if there 3 X / O in a row / col / diagonal (should be in a function)
        */

        /* 
        * Option 2: plaver v computer
        * Display board, prompt player (X)
        * read info (Format: # #; (1-3), (1-3))
        * Display board with new X, move to computer
        * Randomly place O 
        * keep alternating between player 1 or computer while
        * checking if there's a winner
        */
        while (!winningPlayer)
        {
            int row;
            int col;
            char playerSymbol;

            if(tictactoe.turn == 1)
            {
                playerSymbol = tictactoe.player1Symbol;
            }
            else
            {
                playerSymbol = tictactoe.player2Symbol;
            }

            // Display board and prompt
            if(!(invalidInput && choice == 2 && tictactoe.turn == 2))
            {
                printStatus(tictactoe);
            }

            if(tictactoe.turn == 2 && choice == 2 && !winningPlayer && !(tictactoe.attempts >= 9))
            {
                row = rand() % 4;
                col = rand() % 4;
                if(!invalidInput)
                {
                    printf("Player %d is making a move... and they've chosen %d %d!\n", tictactoe.turn, row, col);
                }
            }
            else
            {
                printf("Player %d: make your move ([#1-3] [#1-3])\n", tictactoe.turn);
                scanf("%d %d", &row, &col);
            }

            invalidInput = false;

            if(row == 1 && col == 1)
            {
                if(checkTile(tictactoe.topLeft, choice))
                {
                    tictactoe.topLeft = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 1 && col == 2)
            {
                if(checkTile(tictactoe.topMiddle, choice))
                {
                    tictactoe.topMiddle = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 1 && col == 3)
            {
                if(checkTile(tictactoe.topRight, choice))
                {
                    tictactoe.topRight = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 2 && col == 1)
            {
                if(checkTile(tictactoe.left, choice))
                {
                    tictactoe.left = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 2 && col == 2)
            {
                if(checkTile(tictactoe.middle, choice))
                {
                    tictactoe.middle = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 2 && col == 3)
            {
                if(checkTile(tictactoe.right, choice))
                {
                    tictactoe.right = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 3 && col == 1)
            {
                if(checkTile(tictactoe.bottomLeft, choice))
                {
                    tictactoe.bottomLeft = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 3 && col == 2)
            {
                if(checkTile(tictactoe.bottomMiddle, choice))
                {
                    tictactoe.bottomMiddle = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else if(row == 3 && col == 3)
            {
                if(checkTile(tictactoe.bottomRight, choice))
                {
                    tictactoe.bottomRight = playerSymbol;
                }
                else
                {
                    invalidInput = true;
                }
            }
            else
            {
                if(!(choice == 2 && tictactoe.turn == 2))
                {
                    printf("INVALID INPUT: That spot doesn't exist! Choose again ([#1-3] [#1-3])\n");
                }
                invalidInput = true;
            }

            winningPlayer = checkIfWinner(tictactoe, playerSymbol);

            if(!invalidInput && !winningPlayer)
            {
                tictactoe.attempts++;
                if(tictactoe.turn == 1)
                {
                    tictactoe.turn = 2;
                }
                else
                {
                    tictactoe.turn = 1;
                }
            }

            if(winningPlayer)
            {
                printStatus(tictactoe);
                printf("Congratulations Player %d! You win!]n", tictactoe.turn);
            }
            else if(tictactoe.attempts >= 9)
            {
                printStatus(tictactoe);
                printf("It's a tie!\n");
                winningPlayer = true;
            }

            fflush(stdin);
            

        }

    // asks user if they want to play again
    bool isYesOrNo = false;
    char yesOrNo;
    
    while(!isYesOrNo)
    {
        fflush(stdin);
        printf("Would you like to play again? (y/n)\n");
        scanf("%c", &yesOrNo);

        if(yesOrNo == 'y' || yesOrNo == 'n')
        {
            isYesOrNo = true;
            if(yesOrNo == 'y')
            {
                playAgain = true;
            }
        }
        else
        {
            printf("INVALID INPUT: Please answer in either yes or no (y/n)\n\n");
        }
    }

    }
    return 0;
}

// prints status of the tictactoe board
void printStatus(struct Board board)
{
    printf("The current status:\n");
    printf("+-----------+ \n| %c | %c | %c | \n", board.topLeft, board.topMiddle, board.topRight);
    printf("+-----------+ \n| %c | %c | %c | \n", board.left, board.middle, board.right);
    printf("+-----------+ \n| %c | %c | %c | \n", board.bottomLeft, board.bottomMiddle, board.bottomRight);
    printf("+-----------+ \n\n");
}

// checks if tile is occupied or not, returns true or false depending if the tile is occupied
bool checkTile(char tile, char choice){

    if(tile == 'O' || tile == 'X')
    {
        if(!(choice == 2 && tictactoe.turn == 2))
        {
           printf ("INVALID INPUT: That spot is already chosen! Choose again ([#1-3] [#1-3])\n");
        }
        return false;
    }

    return true;
}

// function that checks if there is 3 X's or O's in a row / col / diagonal 
bool checkIfWinner(struct Board board, char currentSymbol){
    //HORIZONTAL CHECKS
    if(board.topLeft == currentSymbol && board.topMiddle == currentSymbol && board.topRight == currentSymbol)
    {
        //top row
        return true;

    }
    else if(board.left == currentSymbol && board.middle == currentSymbol && board.right == currentSymbol)
    {
        //middle row
        return true;
    }
    else if(board.bottomLeft == currentSymbol && board.bottomMiddle == currentSymbol && board.bottomRight == currentSymbol)
    {
        //bottom row
        return true;
    }
    //VERTICAL CHECKS
    else if(board.topLeft == currentSymbol && board.left == currentSymbol && board.bottomLeft == currentSymbol)
    {
        //left col
        return true;
    }
    else if(board.topMiddle == currentSymbol && board.middle== currentSymbol && board.bottomMiddle == currentSymbol)
    {
        //middle col
        return true;
    }
    else if(board.topRight == currentSymbol && board.right == currentSymbol && board.bottomRight == currentSymbol)
    {
        //right col
        return true;
    }
    //DIAGONAL CHECKS
    else if(board.topLeft == currentSymbol && board.middle == currentSymbol && board.bottomRight == currentSymbol)
    {
        //decreasing slope diagonal check
        return true;
    }
    else if(board.bottomRight == currentSymbol && board.middle == currentSymbol && board.topRight == currentSymbol)
    {
        //inceasing slope diagonal check
        return true;
    }
    else
    {
        return false;
    }
}

// function for random placement of X or O
