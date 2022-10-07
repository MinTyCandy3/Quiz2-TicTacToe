// TIC TAC TOE game between 2 players or player vs computer
#include <stdio.h>

typedef enum { false, true } bool;

int main(){

    // prompt user for game they wish to play   

    int choice;
    bool typeChoice = false;

    printf( "===========================\n");
    printf( "WELCOME TO TIC TAC TOE!\n");
    printf( "1 --- person vs. person\n");
    printf( "2 --- person vs. random computer\n");
    printf( "Enter your choice (1 or 2): ");    

    scanf("%d", &choice);    
    // printf("This is the num: %d", choice);   

    // read information from console (only 1 or 2)
    while(!typeChoice)
    {
            typeChoice = true;
            switch (choice)
            {
            case 1:
                /* code */
                printf("v person");
                break;
            case 2:
                printf("v computer");
                break;
            default:
                typeChoice = false;
                printf("===========================\n");
                printf("Please enter the correct choice (1 or 2): ");
                scanf("%d", &choice);
                break;
            }

    }

    /*
    * Option 1: player v player
    * Display board, prompt player 1 (X)
    * read info (Format: # #; (1-3), (1-3))
    * Display board with new X, prompt player 2 (O)
    * read info 
    * keep alternating between player 1 or 2 while
    * checking if there 3 X / O in a row / col / diagonal (should be in a function)
    */

    // Display board and prompt

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

// function that checks if there is 3 X's or O's in a row / col / diagonal 

// function for random placement of X or O
