//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 3, Problem 2,

#include <stdio.h>

int main()
{
    int pay_counter[10] = {}; // create array to hold counters for pay
    int sales; // holds the employee sales


    printf("Please enter an employees gross sales [enter -1 to stop entry]: "); // query user for sales
    scanf("%d", &sales); // save to sales variable

    int pay = 200 + (.09 * sales); // calculate the pay that the employee receives

    while(sales != -1) // create while loop that stop when exit condition is met
    {
        // use if else statements that save to the correct index depending on what the employee makes.
        if (pay >= 200 && pay <= 299)
            pay_counter[0]++;
        else if (pay >= 300 && pay <= 399)
            pay_counter[1]++;
        else if (pay >= 400 && pay <= 499)
            pay_counter[2]++;
        else if (pay >= 500 && pay <= 599)
            pay_counter[3]++;
        else if (pay >= 600 && pay <= 699)
            pay_counter[4]++;
        else if (pay >= 700 && pay <= 799)
            pay_counter[5]++;
        else if (pay >= 800 && pay <= 899)
            pay_counter[6]++;
        else if (pay >= 900 && pay <= 999)
            pay_counter[7]++;
        else if (pay >= 1000)
            pay_counter[8]++;

        printf("Please enter an employees sales [enter -1 to complete]: "); //query user for new input.
        scanf("%d", &sales); // save input to sales variable.

        pay = 200 + (.09 * sales); // calculate the pay that the employee receives
    }
    int num1 = 200; // variables used to display the possible pay ranges to the user.
    int num2 = 299;

    for(int i = 0; i <= 7; i++) // for loop to iterate through the list and print out all the counters.
    {
        printf("The amount of employees that make between $%d and $%d is %d.\n", num1, num2, pay_counter[i]); // display info to user.
        num1 = num1 + 100; // add 100 to display next pay range correctly.
        num2 = num2 + 100;
    }
    printf("The amount of employees that make $1000 and up is %d.", pay_counter[8]); // display last counter. 

    return 0;
}