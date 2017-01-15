#include <ctype.h>

extern FILE *p;
extern FILE *q;
extern char c;

void whiteSpacing()
{
    while(isblank(c))   //replaces two or more spaces by a single space
    {
        c = getc(p);
        if (!(isspace(c)) && c != EOF)
            putc(' ', q);

    }
    putc(c, q);
}
