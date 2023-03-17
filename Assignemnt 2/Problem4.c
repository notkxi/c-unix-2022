//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 2, Problem 4,

#include <stdio.h>
#include <time.h> // contains prototype for function time
#include <stdlib.h>

//function to simulate the flip of a coin.
int flip()
{
    //returns 0 or 1 randomly.
    return rand() % 2;
}

int main(void)
{
    //randomize number based on time.
    srand(time(NULL));

    //variable used to store amount of times it lands on heads or tails.
    int heads = 0;
    int tails = 0;

    //header to make user friendly.
    printf("Coin Toss Simulator\n");
    printf("-------------------\n");

    //loop the flip function 50000 times.
    for(int i = 1; i <= 50000; i++)
    {
        //increment heads by 1 if flip returns 0.
        if(flip() == 0)
        {
            heads++;
        //increment tails by 1 if flip returns 1.
        }
        else{
            tails++;
        }
    }

    //calculate the percentage of times each side was landed on.
    float heads_percent = (float)heads / 50000 * 100.0;
    float tails_percent = (float)tails / 50000 * 100.0;

    //print out info to the user.
    printf("The coin landed on heads %d times, which accounts for %.2f%% percent.\n", heads, heads_percent);
    printf("The coin landed on tails %d times, which accounts for %.2f%% percent.\n", tails, tails_percent);
    return 0;
}
