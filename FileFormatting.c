#include <stdio.h>
#include "whiteSpacing.c"
#include "lineFolding.c"

FILE *p;
FILE *q;

int main(void)
{
    char c;
    p = fopen("original.txt", "r");      //original file containing input
    q = fopen("formatted.txt", "w");     // file which will contain formatted output

    while((c = getc(p)) != EOF)
    {
        folding(c);
    }
    fclose(p);
    fclose(q);

    p = fopen("formatted.txt", "r");  // this results in output given to the original file itself
    q = fopen("original.txt", "w");

    while((c = getc(p)) != EOF)
    {
        whiteSpacing(c);
    }

    fclose(p);
    fclose(q);

    return 0;
}
