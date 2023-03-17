//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 3, Problem 1,

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

int rollDice(void)
{
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value
    return die1 + die2; // return sum of dice
}

int main()
 {
    srand(time(NULL));
    int sum;
    int roll_freq[13] = {}; // create array to store the amount of times each roll occurs.
    for(int i = 1; i<= 36000; i++) // for loop to roll 36000 times
    {
        sum = rollDice(); // roll the two dice
        roll_freq[sum]++; // add it to the array
    }

    printf("+---------------------------------------+\n"); // header info
    printf("| Sum | Frequency |  Expected |  Actual |\n+---------------------------------------+\n"); // header info


    for(int i = 2; i <= 12 ;i++) // for loop for each possible sum
    {

        float expected_percent = ((6 - abs((i) - 7)) * 100) / (float)36; // formula to calculate the expected percent
        float actual = ((float)roll_freq[i] / 36000) * 100; // formula to calculate the actual percent
        printf("| %-4d| %-10d| %8.2f%% | %6.2f%% |\n", i  ,roll_freq[i] , expected_percent, actual); // print out in a table
    }
    printf("+---------------------------------------+\n"); // header info

     printf("As we can see the expect percentages and actual percentages are similar.\n"); // prove that the totals are reasonable with the percentages.

    return 0;
}
