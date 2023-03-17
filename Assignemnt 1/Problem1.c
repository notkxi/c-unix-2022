//Author: Kai Ibarrondo
//RUID: kai51
//Problem 1, Assignment 1

#include <stdio.h>

int main(void) {
    //initialize the variables needed.
    int total_rows = 8;
    int row, space, star;

    //This for loop is for creating the first 8 rows of the diamond. Should run eight times
    //since we are creating a diamond with 15 stars in the middle.
    for (row = 1; row <= total_rows; row++) {
        //This for loop is for creating the amount of spaces. Takes and decrements the
        //amount of spaces in each iteration.
        for (space = total_rows - row; space >= 1; space--) {
            printf(" ");
        }
        //This for loop is for creating the stars in the diamond. Increments the star variable,
        //It stops when the amount of stars goes over the amount needed to make the diamond.
        for (star = 1; star <= 2 * row - 1; star++) {
            printf("*");
        }
        //Prints newline character to make diamond.
        printf("\n");
    }

    //This for loop creates the last seven rows of the diamond. Should run 7 times for the last
    //Seven rows.
    for (row = total_rows - 1; row >= 1; row--) {
        //This for loop increases the amount of spaces in each row.
        for (space = 1; space <= total_rows - row; space++) {
            printf(" ");
        }
        //This for loop decreases the amount of stars in each row, since it is dependent on the 
        //row variable, and that variable is getting decremented. 
        for (star = 1; star <= 2 * row - 1; star++) {
            printf("*");
        }
        //Prints newline character to make diamond.
        printf("\n");
    }
    return 0;
}