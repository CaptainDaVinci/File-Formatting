#include <ctype.h>

#define MAXLEN 65       //length for wrapping
#define MAXLINE 1000    // maximum length for one line
extern char c;

int getLine(FILE *, FILE *, char *);
void wrap(char *);

void lineWrapping(FILE *infile, FILE *outfile)
{
    char line[MAXLINE];
    int len;

    while((len = getLine(infile, outfile, line)) > 1) // proceed only if length of line is greater than 1
    {
        if(len > MAXLEN)    // fold the length only if length of line is greater than the MAXLEN.
        {
            wrap(line);
        }

        whiteSpacing(infile, outfile, line, len);
        //fprintf(outfile, "%s", line);
    }

}

int getLine(FILE *infile, FILE *outfile, char line[])
{
    int nc = 0;
    while(((c != EOF)) && c != '\n' && nc < MAXLINE - 2)  // store each character of a line in an array.
    {
        line[nc] = c;
        nc++;
        c = getc(infile);
    }
    if(c == '\n')
        line[nc] = '\n';

    line[nc + 1] = '\0';
    return nc + 1;
}

void wrap(char line[])
{
    int i = 0;
    int lastBlank = 0;
    int j = 1;

    for(i = 0; line[i] != '\0'; i++)
    {
        if(isspace(line[i]))   // kees track of the last white Spacing.
        {
            lastBlank = i;
        }

        if(i == MAXLEN * j)    //prints a new line at every MAXLEN interval
        {
            line[lastBlank] = '\n';
            j++;
        }
    }

    line[i + 1] = '\0';
}
