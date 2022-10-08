// TIC TAC TOE game between 2 players or player vs computer
#include <stdio.h>

typedef enum { false, true } bool;

struct Board
{
    /* data */
    int turn;
    char player1Symbol, player2Symbol;

    char topLeft, topMiddle, topRight, left, middle, right, bottomLeft, bottomMiddle, bottomRight;
};

void initializeBoard(struct Board board, int choice);

void printStatus(struct Board board);

bool checkTile(char tile);

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

    tictactoe.topLeft = ' ';
    tictactoe.topMiddle = ' ';
    tictactoe.topRight = ' ';
    tictactoe.left = ' ';
    tictactoe.middle = ' ';
    tictactoe.right = ' ';
    tictactoe.bottomLeft = ' ';
    tictactoe.bottomMiddle = ' ';
    tictactoe.bottomRight = ' ';

    tictactoe.middle = tictactoe.player1Symbol;

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
        printf("Player%d: make your move\n", tictactoe.turn);
        scanf("%d %d", &row, &col);

        if(row == 1 && col == 1)
        {
            checkTile(tictactoe.topLeft);
            tictactoe.topLeft = playerSymbol;
        }
        else if(row == 1 && col == 2)
        {
            checkTile(tictactoe.topMiddle);
            tictactoe.topMiddle = playerSymbol;
        }
        else if(row == 1 && col == 3)
        {
            checkTile(tictactoe.topRight);
            tictactoe.topRight = playerSymbol;
        }
        else if(row == 2 && col == 1)
        {
            checkTile(tictactoe.left);
            tictactoe.left = playerSymbol;
        }
        else if(row == 2 && col == 2)
        {
            checkTile(tictactoe.middle);
            tictactoe.middle = playerSymbol;
        }
        else if(row == 2 && col == 3)
        {
            checkTile(tictactoe.right);
            tictactoe.right = playerSymbol;
        }
        else if(row == 3 && col == 1)
        {
            checkTile(tictactoe.bottomLeft);
            tictactoe.bottomLeft = playerSymbol;
        }
        else if(row == 3 && col == 2)
        {
            checkTile(tictactoe.bottomMiddle);
            tictactoe.bottomMiddle = playerSymbol;
        }
        else if(row == 3 && col == 3)
        {
            checkTile(tictactoe.bottomRight);
            tictactoe.bottomRight = playerSymbol;
        }

        printf("%c", tictactoe.topLeft);

        if(tictactoe.turn == 1)
        {
            tictactoe.turn = 2;
        }
        else
        {
            tictactoe.turn = 1;
        }

        

    }

    // Read

    // Repeat . . .

    // Check if there's a winner

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
    printf("+-----------+ \n");
}

// checks if tile is occupied or not, returns true or false depending if the tile is occupied
bool checkTile(char tile){

    if(tile == 'O' || tile == 'X')
    {
        return false;
    }

    return true;
}

// function that checks if there is 3 X's or O's in a row / col / diagonal 

// function for random placement of X or O
