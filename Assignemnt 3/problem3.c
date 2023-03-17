//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 3, Problem 3,

#include <stdio.h>

int getUnique(int arr[]) // make function to find unique numbers in the union of the two arrays
{
    int j; // initialize variable to use for second for loop
    for (int i = 0; i < 20; i++) // make for loop to compare one number to every number in the array
    {
        for (j = 0; j < 20; j++) // use for loop to iterate through the array a second time to compare values.
        {
            if (arr[i] == arr[j] && i != j) // if the values are the same and are not in the same index then break out of the for loop as the number is not unique(occurring once)
                break;
        }
        if (j == 20) // when the inner for loop is able to reach 20 print out the value as it has no repeats in the array.
            printf("%d ", arr[i]); //print out the number
        }
}

int main()
{
    int num_set1[11], num_set2[11], uni[20]; // create two empty arrays to store numbers

    printf("Enter the first set of 10 numbers (include spaces between numbers): \n");
    for(int i = 0; i < 10; i++) // for loop to store 10 numbers
    {
        scanf("%d",&num_set1[i]); // enter numbers in first array
    }

    printf("Enter the second set of 10 numbers (include spaces between numbers): \n");
    for(int i = 0; i < 10; i++) // for loop to store 10 numbers
    {
        scanf("%d",&num_set2[i]); // enter numbers in second array
    }

    for(int i = 0; i <= 10; i++) // for loop to create a union to the two arrays
    {
        uni[i] = num_set1[i];
    }


    for(int i = 0; i <= 10; i++) // for loop to create a union of the two arrays
    {
        uni[i + 11] = num_set2[i];
    }

    printf("The unique elements in the collection of both sets of numbers are: \n"); // print out header
    getUnique(uni); //call getUnique function

    printf("\nThank you for using!\n");
    return 0;
}
