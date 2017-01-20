#include <stdio.h>

#define MAXWORD 15
#define VOWELS 'a' || 'e' || 'i' || 'o' || 'u' || 'A' || 'E' || 'I' || 'O' || 'U'

void histogram(int []);
int highestWordLen(int []);

void stats(FILE *outfile)
{
    int  nc, i, lines, wordLength, vowels;
    int wordLen[MAXWORD];
    lines = nc  = wordLength = vowels = 0;

    for(i = 1; i < MAXWORD; i++)
        wordLen[i] = 0;

    while((c = getc(outfile)) != EOF)
    {
        while(c != ' ' && c != '\n' && c != '\t')
        {
            nc++;
            wordLength++;

            if(c == VOWELS)
                vowels++;

            c = getc(outfile);
        }

        if(c == '\n')
            lines++;

        nc++;
        wordLen[wordLength]++;
        wordLength = 0;
    }

    histogram(wordLen);

    printf("\n\n\tCHARACTERS   - %3d", nc);
    printf("\n\tLINES        - %-3d", lines);
    printf("\n\tVOWELS       - %-3d", vowels);
    printf("\n\tLONGEST WORD - %d\n\n", highestWordLen(wordLen));
}

void histogram(int wordLen[])
{
    int i, j;
    printf("\n\nLength of a word VS Number of words\n");

    for(i = 1; i < MAXWORD; i++)
    {
        printf("\n%2d | ", i);
        for(int j = 0; j < wordLen[i]; j++)
        {
            printf(" *");
        }
    }
}

int highestWordLen(int wordLen[])
{
    int highest = 0;
    int i;

    for(i = 1; i < MAXWORD; i++)
    {
        if(wordLen[i] > highest)
            highest = wordLen[i];
    }

    return highest;
}
