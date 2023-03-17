//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 2, Problem 3,

#include <stdio.h>

//recursive function that returns two number multiplied together.
int multiply(int x, int y){
    //base case. returns zero when x or y are zero.
    if(x == 0 || y == 0){
        return 0;
    }
    //recursive function that passes through x, y-1, until y = 0.
    else{
        return x + multiply(x, y-1);
    }
}

int main()
{
    //initialize the two numbers used.
    int x;
    int y;

    //query user for the two number they want multiplied.
    printf("Enter first number: ");
    scanf("%d", &x);

    printf("Enter second number: ");
    scanf("%d", &y);

    //print out the result.
    printf("The product of %d and %d is %d", x, y, multiply(x, y));

    return 0;
}
