
//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 2, Problem 2,


#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice(void); // function prototype
int one_game(void); // function prototype

// roll dice, calculate sum and display results
int rollDice(void)
{
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value

    // display results of this roll
    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    return die1 + die2; // return sum of dice
}

int one_game(void)
{
    srand(time(NULL));

    int myPoint; // player must make this point to win
    enum Status gameStatus; // can contain CONTINUE, WON, or LOST
    int sum = rollDice(); // first roll of the dice

    // determine game status based on sum of dice
    switch(sum) {

        // win on first roll
        case 7: // 7 is a winner
        case 11: // 11 is a winner
            gameStatus = WON;
            break;

            // lose on first roll
        case 2: // 2 is a loser
        case 3: // 3 is a loser
        case 12: // 12 is a loser
            gameStatus = LOST;
            break;

            // remember point
        default:
            gameStatus = CONTINUE; // player should keep rolling
            myPoint = sum; // remember the point
            printf("Point is %d\n", myPoint);
            break; // optional
    }

    // while game not complete
    while (CONTINUE == gameStatus) { // player should keep rolling
        sum = rollDice(); // roll dice again

        // determine game status
        if (sum == myPoint) { // win by making point
            gameStatus = WON;
        }
        else {
            if (7 == sum) { // lose by rolling 7
                gameStatus = LOST;
            }
        }
    }

    // display won or lost message
    if (WON == gameStatus) { // did player win?
        puts("Player wins");
        return 1;
    }
    else { // player lost
        puts("Player loses");
        return 0;
    }
}


int main(void)
{
    //welcome user.
    printf("\t\tWelcome to the Craps Program!\n\n");

    //initialize bank balance.
    float initial_balance = 2000;
    int keep_playing;

    //inform user for current balance.
    printf("Your initial bank balance is $%.2f\n\n", initial_balance);

    //keep the while loop going until user has no more money.
    while(initial_balance > 0)
    {
        //query user how much money they want to wager.
        float wager;
        printf("What is your wager?");
        scanf("%f", &wager);

        //if the wager is more than the user has then prompt them to enter a correct wager until they do.
        while(wager > initial_balance)
        {
            printf("Cannot wager more than $%.2f. Re-enter wager:  ", initial_balance);
            scanf("%f", &wager);
        }
        printf("Okay, let's play.\n");

        //start the game.
        int results = one_game();

        //reflect users balance, if they win or lose.
        switch(results){
            case 0:
                initial_balance -= wager;
                printf("\nYour new bank balance is $%.2f.\n\n", initial_balance);
                break;
            case 1:
                initial_balance += wager;
                printf("\nYour new bank balance is $%.2f.\n\n", initial_balance);
                break;
        }

        //if the user runs out of money, tell them and end the program.
        if(initial_balance == 0) {
            printf("You're broke!");
            break;
        }

        //query user if they want to keep playing.
        printf("Would you like to continue?[-1 to exit, 0 to continue]");
        scanf("%d", &keep_playing);

        //if they enter -1 then print out their balance, and inform if they lost or gained money.
        if(keep_playing == 0)
        {
            printf("Let roll!\n\n");
            continue;
        }

        if(keep_playing == -1)
        {
            printf("You final total is %.2f\n", initial_balance);
            if(initial_balance >= 2000)
            {
                printf("Good job!\nGoodbye!");
                break;
            }
            else
            {
                printf("Better luck next time.\nThanks for playing!");
                break;
            }
        }
    }
    return 0;
}



