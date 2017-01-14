#include <stdio.h>
#include <stdlib.h>
#include "whiteSpacing.c"
#include "lineFolding.c"

FILE *p;
FILE *q;

int main(void)
{
    char c;
    p = fopen("original.txt", "r");      //original file containing input
    q = fopen("formatted.txt", "w");     // file which will contain formatted output

    if(p == NULL || q == NULL)
    {
        printf("ERROR! Unable to open file\n"); // exit out of the program if file does not exist.
        exit(1);
    }

    while((c = getc(p)) != EOF)
    {
        folding(c);
    }

    fclose(p);
    fclose(q);

    p = fopen("formatted.txt", "r");  // this results in output given to the original file itself
    q = fopen("original.txt", "w");

    if(p == NULL || q == NULL)
    {
        printf("ERROR! Unable to open file\n");
        exit(1);
    }

    while((c = getc(p)) != EOF)
    {
        whiteSpacing(c);
    }

    fclose(p);
    fclose(q);

    return 0;
}
