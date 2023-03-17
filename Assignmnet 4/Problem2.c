//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 4, Problem 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck

void deal(unsigned int wDeck[][FACES], const char *wFace[],
          const char *wSuit[]); // dealing doesn't modify the arrays

void printArray(int deck[SUITS][FACES]);

int main(void)
{
    // initialize deck array
    unsigned int deck[SUITS][FACES] = {0};

    srand(time(NULL)); // seed random-number generator

    shuffle(deck); // shuffle the deck

    // initialize suit array
    const char *suit[SUITS] =
            {"Hearts", "Diamonds", "Clubs", "Spades"};

    // initialize face array
    const char *face[FACES] =
            {"Ace", "Deuce", "Three", "Four",
             "Five", "Six", "Seven", "Eight",
             "Nine", "Ten", "Jack", "Queen", "King"};

    int card = 1; //count amount of cards

    //insert cards into deck
    while(card < CARDS)
    {
        for(int i = 0; i < SUITS; i++)
        {
            for(int j = 0; j < FACES; j++)
            {
                deck[i][j] = card; //insert card into the 2D array
                card++;
            }
        }
    }

    printf("UNSHUFFLED DECK ARRAY\n---------------------\n"); //print out unshuffled deck
    printArray(deck); //call print array function

    printf("\n\nSHUFFLED DECK ARRAY\n-------------------\n"); //print out shuffled deck
    for(int i = 0; i <= 7; i++) //shuffle deck seven times
    {
        shuffle(deck);
    }
    printArray(deck); // call print array function

    return 0;
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
    for(int i = 0; i < SUITS; i++) // loop through rows
    {
        for (int j = 0; j < FACES; j++) // loop columns rows
        {
            int new_row = rand() % SUITS; //create random row
            int new_col = rand() % FACES; //create random column

            int temp =  wDeck[i][j]; // temporary value to access card
            wDeck[i][j] =  wDeck[new_row][new_col]; // switch numbers
            wDeck[new_row][new_col] = temp; // save temporary value to the new position in the deck
        }
    }
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
          const char *wSuit[])
{
    // deal each of the cards
    for (size_t card = 1; card <= CARDS; ++card) {
        // loop through rows of wDeck
        for (size_t row = 0; row < SUITS; ++row) {
            // loop through columns of wDeck for current row
            for (size_t column = 0; column < FACES; ++column) {
                // if slot contains current card, display card
                if (wDeck[row][column] == card) {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                           card % 2 == 0 ? '\n' : '\t'); // 2-column format
                }
            }
        }
    }
}

void printArray(int deck[SUITS][FACES])
{
    int row, col; //initialize row and column variables

    printf("%10d",0); //print out first zero row with 10 space buffer

    for(col = 1; col < FACES; col++) //print out first row
    {
        printf("%5d", col);
    }

    printf("\n"); //add new line

    for(row = 0; row < SUITS; row++) // print out left more numbers
    {
        printf("%5d", row);
        for(col = 0; col < FACES; col++) // print out 13 numbers from the deck for each loop
        {
            printf("%5d", deck[row][col]);
        }
        printf("\n");
    }
}


