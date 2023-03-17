//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 5, Problem 1

#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fPointer; // file pointers.
    FILE *newfPointer;

    int chara; // used to hold each character.
    int digit = 0, alpha = 0, low_case = 0, up_case = 0, space = 0, punct = 0, graph = 0; // used to store the counters for each of the character types

    newfPointer = fopen("C_Language_Convert.txt", "w"); // create file for the converted cases.

    if ((fPointer = fopen("C_Language.txt","r")) == NULL) // error handling if file not found.
    {
        printf("Error! Can't open file!");
    }

    else
    {
        while ((chara = fgetc(fPointer)) != EOF) // loop until the end of the file.
        {
            if(isdigit(chara)) // check if the character is a digit and write it to the file.
            {
                fputc(chara, newfPointer);
                digit++; // increment appropriate counter.
            }
            if(isspace(chara)) // check if the character is a space and write it to the file.
            {
                fputc(chara, newfPointer);
                space++; // increment appropriate counter.
            }
            if (ispunct(chara)) // check if the character is punctuation and write it to the file.
            {
                fputc(chara, newfPointer);
                punct++; // increment appropriate counter.
            }
            if (isgraph(chara)) // check if the character is a graph and write it to the file.
            {
                graph++; // increment appropriate counter.
            }
            if (isalpha(chara)) // check if the character is an alphabet character.
            {
                alpha++; // increment appropriate counter.
                if(islower(chara)) // check if the character is lowercase and write it to the file.
                {
                    fputc(toupper(chara), newfPointer);
                    low_case++; // increment appropriate counter.
                }
                if(isupper(chara)) // check if the character is uppercase and write it to the file.
                {
                    fputc(tolower(chara), newfPointer);
                    up_case++; // increment appropriate counter.
                }
            }
        }

        printf("The statistics of the text file are as follows...\n"); // print out the statistics to the user.
        printf("There are %d digits.\n", digit);
        printf("There are %d letters.\n", alpha);
        printf("There are %d lowercase letters.\n", low_case);
        printf("There are %d uppercase letters.\n", up_case);
        printf("There are %d spaces.\n", space);
        printf("There are %d punctuation marks.\n", punct);
        printf("There are %d graphical characters.\n", graph);
        fclose(fPointer);
        fclose(newfPointer);
    }
    return 0;
}