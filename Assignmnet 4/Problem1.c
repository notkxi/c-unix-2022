//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 4, Problem 1

#include <stdio.h>

void concatenate(char *arr1, char *arr2); //function prototype

int main()
{
    char input1[20], input2[20]; // create two arrays that can hold 20 chars


    printf("Enter the first string: "); //query user for first string
    gets(input1); //use gets method to allow for white space
    printf("Enter the second string: "); //query user for second string
    gets(input2); //use gets method to allow for white space
    printf("The concatenate string is...\n"); //output

    concatenate(input1, input2); //call concatenate function

    return 0;
}


void concatenate(char *arr1, char *arr2) //take two pointers that point the two original arrays
{
    char output[40]; //create new string to hold the chars

    char *output_ptr = output; //create pointer that points to the new string

    while(*arr1 != '\0') //cycle through first array until we reach null char
    {
        *output_ptr = *arr1; //append arr1 to output array
        output_ptr++; //move pointer one space forward
        arr1++; //move pointer one space forward
    }

    while(*arr2 != '\0') // continue loop until we are at the null character
    {
        *output_ptr = *arr2; //append arr2 to the end of arr1
        output_ptr++; //move pointer one space forward
        arr2++; //move pointer one space forward
    }

    *output_ptr = '\0'; //add null char at the end

    puts(output); //display array
}
