//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 6, Problem 1,

#include <stdio.h>

struct part //define structure to hold two variables
{
    unsigned int partNumber;
    char partName[25];
};

typedef struct part Part; //create alias for part name Part

Part a; // variable of type part      
Part b[10]; // array of type part 
Part *ptr; // pointer of type part 

int main()
{
    printf("Enter a number: "); //query user for number
    scanf("%u", &a.partNumber); //save input to instance a

    printf("Enter a name: "); //query user for name
    scanf("%s", a.partName);  //save input to instance a

    b[2] = a; // save the instance (a) to the second index of the array b 

    ptr = b; //assign the pointer prt to the array b 

    printf("Part number: %u\n", (ptr + 2) -> partNumber); //using pointer operator refer to the member value at the second index
    printf("Part name: %s\n", (ptr + 2) -> partName); //using pointer operator refer to the member value at the second index

    return 0;
}