//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 2, Problem 1,

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//creates the question asked the user.
int create_question()
{
    //creates two random numbers.
    unsigned int first_num =  10 + rand() % 89;
    unsigned int second_num =  10 + rand() % 89;

    //query user for answer.
    printf("How much is %u times %u? ", first_num, second_num);

    //return correct answer.
    return first_num * second_num;
}


int main(void){
    //randomize number using time.
    srand(time(NULL));

    //header to make user friendly.
    printf("\t\tWelcome to the Multiplication Program!\n");
    printf("To exit from this program enter -1, Let's start!\n\n");

    //initialize variables for later use.
    int user_answer = 0;
    int right_answer = 0;

    //while the user does not enter -1 keep the program running.
    while(user_answer != -1){
        right_answer = create_question();

        //query user for answer.
        printf("\n\nEnter your answer: ");
        scanf("%d", &user_answer);

        //if the user is correct congratulate them.
        if(user_answer == right_answer)
        {
            printf("Very Good!\n");
            printf("Let try another!\n");
        }

        //if the user is wrong prompt them to try again until they get it right.
        while(user_answer != right_answer && user_answer != -1)
        {
            printf("No. Please try again.\n\n");
            printf("Enter your new answer: ");
            scanf("%d", &user_answer);

            //
            if(user_answer == right_answer)
            {
                printf("Very Good!\n");
                printf("Let try another!\n");
            }

        }

    }
    //thank user.
    printf("Thanks for using!");
    return 0;
}