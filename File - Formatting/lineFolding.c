#include <ctype.h>

#define MAXLEN 65       //length for wrapping
#define MAXLINE 1000    // maximum length for one line

extern FILE *p;
extern FILE *q;
extern char c;

int getLine(char *);
void trim(char *);

void folding(void)
{
    char line[MAXLINE];
    int len;

    while((len = getLine(line)) > 1) // proceed only if length of line is greater than 1
    {
        if(len > MAXLEN)    // fold the length only if length of line is greater than the MAXLEN.
        {
            trim(line);
        }
        fprintf(q, "%s", line);
    }

}

int getLine(char line[])
{
    int nc = 0;
    while(((c != EOF)) && c != '\n')  // store each character of a line in an array.
    {
        line[nc] = c;
        nc++;
        c = getc(p);
    }
    if(c == '\n')
        line[nc] = '\n';

    line[nc + 1] = '\0';
    return nc + 1;
}

void trim(char line[])
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
