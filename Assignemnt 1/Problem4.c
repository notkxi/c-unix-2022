//Author: Kai Ibarrondo
//RUID: kai51
//Problem 4, Assignment 1

#include <stdio.h>

int main() {
    //Print out header for the triples.
    printf("The pythagorean triples upto 500 are...\n");
    printf("Side 1\tSide 2\tHypotenuse\n");
    //create variables to represent 3 sides of triangle.
    int a, b, c;
    //Use brute force method to check every single value of a, b, and c up to 500.
    for(a = 1; a <= 500; a++){
        for(b = 1; b <= 500; b++){
            for(c = 1; c<= 500; c++) {
                //if the pythagorean theorem is true then print out the pythagorean triple.
                if (a * a + b * b == c * c) {
                    printf("%d\t%d\t%d\t\n", a, b, c);
                }
            }
        }
    }
    return 0; 
}