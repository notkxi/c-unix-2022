//Author: Kai Ibarrondo
//RUID: kai51
//Assignment 5, Problem 1,

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *textFile; // file pointer.
    textFile = fopen("C_Language.txt", "r"); // open file for reading.

    char line[500]; // array to save one line.
    int word_count = 0; // word count counter.

    if (textFile == NULL) // error message if file cannot be open.
    {
        puts("Unable to open file.");
    }

    else
    {
        while(fgets(line, 500, textFile) != NULL) // loop until the file ends.
        {
            char *token = strtok(line, " "); // load first token, (which is the first word)
            while(token != NULL)
            {

                token = strtok(NULL, " "); // cycle through tokens
                word_count++; // increment word count
            }
        }
    }

    printf("The number of words in the C_Language.txt file is: %d", word_count); // print amount of words to user
    fclose(textFile); // close file
}
