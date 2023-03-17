//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 6, Problem 2,

#include <stdio.h>

void display(unsigned int num); //function prototype to display integer in binary
unsigned int reverseBits(unsigned int num); //function prototype to reverse binary

int main()
{
    unsigned int num; //variable to store user input

    printf("Enter a number: "); //query user for number
    scanf("%u", &num); //save input to num variable
    printf("Original value in bits is: "); //print out the user input in binary
    display(num); //call display function to display the bytes

    printf("\nReversed value in bits is: "); //print out the reverse of input in binary
    display(reverseBits(num)); //call the reverse bits function within the display bits function to print out the binary

    return 0;
}

unsigned int reverseBits(unsigned int num)
{
    unsigned int reversed = 0; //initialize the binary string we will be returning

    for (unsigned int c = 1; c <=  32; c++) //loop 32 times to result in a 32-bit integer
    {
        reversed <<= 1; //shift the integer stored by one bit to the left so that th
        //this algorithm stores the result of reversed | (num & 1) back to reversed the | operator is used to store the
        //result back to variable (num & 1) then returns 1 if there is a 1 located in the specific byte in the num variable
        reversed = reversed | (num & 1);
        num >>= 1; //shift num 1 to the right to compare every byte in the num variable
    }
    return reversed; //return reversed value
}

void display(unsigned int num) //take unsigned integer as argument
{
    unsigned int mask = 1 << 31; //create a bit mask (shift one 31 bits to the left)

    for (unsigned int c = 1; c <=  32; c++) //loop 32 times to result in a 32-bit integer
    {
        // this algorithm prints out a "1" if (num & mask) result in true, otherwise it prints a "0"
        // (num & mask) return true if there is a 1 located in the same bit in the integers num and mask
        printf("%c", num & mask ? '1' : '0');
        mask >>= 1; // shift the mask by 1 bit to the right to compare the mask with every bit in the user input

        if(c % 8 == 0) //use if statement to leave a space every eighth digit for easier readability
        {
            printf(" ");
        }
    }
}