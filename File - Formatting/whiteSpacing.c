#include <stdio.h>

extern FILE *p;
extern FILE *q;

void whiteSpacing(char c)
{
    while(c == ' ')   //replaces two or more spaces by a single space
    {
        c = getc(p);
        if (c != ' ' && c != '\n' && c != EOF)
            putc(' ', q);
    }
    putc(c, q);
}
