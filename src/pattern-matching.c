#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

int getNewLine(FILE *infile, char *line);

void matchPattern(FILE *infile, char *pattern)
{
    int i, j;
    int len = strlen(pattern);
    char line[MAXLINE];

    while(getNewLine(infile, line) > 0)
    {
        if(strstr(line, pattern) != NULL)
            printf("%s", line);
    }
}

int getNewLine(FILE *infile, char *line)
{
    int i = 0;
    int c;

    while((c = getc(infile)) != EOF && c != '\n')
        line[i++] = c;

    if(c == '\n')
        line[i++] = '\n';

    line[i] = '\0';

    return i;
}
