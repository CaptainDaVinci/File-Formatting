#include <stdio.h>
#include <ctype.h>

#define MAXWORD 15
#define VOWELS(c) ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
#define PUNCTUATION(c) ((c != ' ') && (c != '\n') && (c != '\t') && (c != '.') && (c != ',') && (c != '!'))

void histogram(int []);
int highestWordLen(int []);
int countWords(int []);
void resetWord(char []);

void stats(FILE *outfile)
{
    int nc, i, lines, wordLength, vowels;
    int wordLen[MAXWORD];
    char word[MAXWORD], longestWord[MAXWORD];
    lines = nc  = wordLength = vowels = 0;
    longestWord[1] = '\0';

    for(i = 1; i <= MAXWORD; i++)
        wordLen[i] = 0;


    while((c = getc(outfile)) != EOF)
    {
        i = 0;

        // calculates the length of each word.
        while(PUNCTUATION(c))
        {
            word[i] = c;
            nc++;
            wordLength++;
            i++;

            if(VOWELS(tolower(c)))
                vowels++;

            c = getc(outfile);
        }

        word[i] = '\0';

        //  stores the longest word in the file
        if(strlen(word) > strlen(longestWord))
        {
            resetWord(longestWord);
            strcpy(longestWord, word);
            resetWord(word);
        }

        if(c == '\n')
            lines++;

        nc++;
        wordLen[wordLength]++;
        wordLength = 0;
    }

    histogram(wordLen);

    printf("\n\nCharacters\tLines\tWords\tVowels\t Longest Word\n");
    printf(" %d\t\t %d\t %d\t %d\t '%s'\n", nc, lines, countWords(wordLen), vowels, longestWord);
}

void histogram(int wordLen[])
{
    int i, j;
    printf("\n\nLength of a word VS Number of words\n");

    // creates a histogram of length of a word vs numbers of words of given length.
    for(i = 1; i <= MAXWORD; i++)
    {
        printf("\n%2d | ", i);
        for(int j = 0; j < wordLen[i]; j++)
        {
            printf("* ");
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
            highest = i;
    }

    return highest;
}

int countWords(int wordLen[])
{
    int count = 0;

    for(int i = 1; i < MAXWORD; i++)
    {
        count += wordLen[i];
    }

    return count;
}

void resetWord(char word[])
{
    for(int i = 0; i < MAXWORD; i++)
    {
        word[i] = ' ';
    }
}
