#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Formatting.h"

#define MAXWORD 15
#define VOWELS(c) ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
#define PUNCTUATION(c) ((c != ' ') && (c != '\n') && (c != '\t') && (c != '.') && (c != ',') && (c != '!'))

void histogram(int words[]);
int countWords(int []);

void stats(FILE *outfile)
{
    char c;
    int nc, i;
    int lines, wordLen, vowels;
    int *words = calloc(MAXWORD, sizeof(*words));
    char newWord[MAXWORD], longestWord[MAXWORD];

    lines = nc  = wordLen = vowels = 0;
    longestWord[1] = '\0';

    while((c = getc(outfile)) != EOF)
    {
        i = 0;
        wordLen = 0;

        // calculates the length of each word.
        while(PUNCTUATION(c))
        {
            newWord[i++] = c;
            wordLen++;
            nc++;

            if(VOWELS(tolower(c)))
                vowels++;

            c = getc(outfile);
        }

        newWord[i] = '\0';

        //  stores the longest word in the file
        if(strlen(newWord) > strlen(longestWord))
            strcpy(longestWord, newWord);

        if(c == '\n')
            lines++;

        nc++;
        words[wordLen]++;
    }

    histogram(words);

    printf("\n\nCharacters\tLines\tWords\tVowels\t Longest Word\n");
    printf(" %d\t\t %d\t %d\t %d\t '%s'\n", nc, lines, countWords(words), vowels, longestWord);

    free(words);
}

void histogram(int words[])
{
    int i, j;
    printf("\n\nLength of a word VS Number of words\n");

    // creates a histogram of length of a word vs numbers of words of given length.
    for(i = 1; i <= MAXWORD; i++)
    {
        printf("\n%2d | ", i);
        for(j = 0; j < words[i]; j++)
        {
            printf("* ");
        }
    }
}

int countWords(int words[])
{
    int count = 0;

    for(int i = 1; i < MAXWORD; i++)
        count += words[i];

    return count;
}
