//Author: Kai Ibarrondo
//RUID: kai51
//Problem 2, Assignment 1

#include <stdio.h>

int main() {
    //Initialize variable needed.
    int account_number;
    double credit_limit;
    float current_bal;

    //This for loop runs three times to ask the user for three different customers.
    for(int i = 1; i  <= 3; i++){
        //These print and scan commands query the user for the different
        //information needed to process their bank account and save it to the
        //appropriate variables.
        printf("Enter the customer's account number: ");
        scanf("%d",&account_number);
        printf("Enter the customer's credit limit before recession: ");
        scanf("%lf",&credit_limit);
        printf("Enter the customer's current balance: ");
        scanf("%f",&current_bal );
        //Calculate users new credit limit.
        credit_limit = (credit_limit * .8);
        //Print out the users new credit limit.
        printf("The current credit limit for account %d is %.2f\n",account_number, credit_limit);
        //Calculate if the users balance is over the new credit limit. Print out the result.
        if(current_bal > credit_limit){
            printf("The users balance exceeds the limit\n\n");
        }
        else{
            printf("The users balance does not exceed the limit\n\n");
        }
    }
    return 0;
}