// TIC TAC TOE game between 2 players or player vs computer
#include <stdio.h>

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

bool checkTile(char tile);

bool checkIfWinner(struct Board board, char currentSymbol);

int main(){

    // prompt user for game they wish to play   

    int choice;
    bool typeChoice = false;
    bool winningPlayer = false;
    struct Board tictactoe;

    printf( "===========================\n");
    printf( "WELCOME TO TIC TAC TOE!\n");
    printf( "1 --- person vs. person\n");
    printf( "2 --- person vs. random computer\n");
    printf( "Enter your choice (1 or 2): ");    

    scanf("%d", &choice);     

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
                break;
            case 2:
                printf( "===========================\n");
                printf("You have entered choice 2\n");
                break;
            default:
                typeChoice = false;
                printf("===========================\n");
                printf("Please enter the correct choice (1 or 2): ");
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
    while (!winningPlayer)
    {
        int row;
        int col;
        char playerSymbol;
        bool invalidInput = false;

        if(tictactoe.turn == 1)
        {
            playerSymbol = tictactoe.player1Symbol;
        }
        else
        {
            playerSymbol = tictactoe.player2Symbol;
        }

        // Display board and prompt
        printStatus(tictactoe);
        printf("Player %d: make your move ([#1-3] [#1-3])\n", tictactoe.turn);
        scanf("%d %d\n", &row, &col);

        if(row == 1 && col == 1)
        {
            if(checkTile(tictactoe.topLeft))
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
            if(checkTile(tictactoe.topMiddle))
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
            if(checkTile(tictactoe.topRight))
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
            if(checkTile(tictactoe.left))
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
            if(checkTile(tictactoe.middle))
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
            if(checkTile(tictactoe.right))
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
            if(checkTile(tictactoe.bottomLeft))
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
            if(checkTile(tictactoe.bottomMiddle))
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
            if(checkTile(tictactoe.bottomRight))
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
            printf("INVALID INPUT: That spot doesn't exist! Choose again ([#1-3] [#1-3])\n");
            invalidInput = true;
        }

        winningPlayer = checkIfWinner(tictactoe, playerSymbol);

        if(winningPlayer)
        {
            printStatus(tictactoe);
            printf("Congratulations Player %d! You win!", tictactoe.turn);
        }
        else if(tictactoe.attempts >= 9)
        {
            printf("It's a tie!");
        }

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


    }

    /* 
    * Option 2: plaver v computer
    * Display board, prompt player (X)
    * read info (Format: # #; (1-3), (1-3))
    * Display board with new X, move to computer
    * Randomly place O (should be in a function)
    * keep alternating between player 1 or computer while
    * checking if there's a winner
    */

    // Display board and prompt

    // Read

    // Repeat . . .

    // Check if there's a winner

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
bool checkTile(char tile){

    if(tile == 'O' || tile == 'X')
    {
        printf ("INVALID INPUT: That spot is already chosen! Choose again ([#1-3] [#1-3])\n");
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
