#include <stdio.h>
#include <stdlib.h>
#include "whiteSpacing.c"
#include "lineFolding.c"

FILE *p;
FILE *q;
char c;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error! Check number of arguements.\n");
        exit(-1);
    }

    p = fopen(argv[1], "r");                //original file containing input
    q = fopen("temporary.txt", "w");

    if(p == NULL || q == NULL)          //error checking, also asks user if file is to be created.
    {
        printf("ERROR! Unable to open file\nDo you want to create '%s' file ? (y/n)\n", argv[1]);
        c = getchar();

        if(c == 'y' || c == 'Y')
        {
            p = fopen(argv[1], "w+");
            printf("Type here to write to the file\n");

            while((c = getchar()) != EOF)
            {
                putc(c, p);
            }
            fclose(p);

            p = fopen(argv[1], "r");
        }

        else
            exit(1);
    }

    while((c = getc(p)) != EOF)   // for line wrapping
    {
        folding();
    }

    fclose(p);
    fclose(q);

    p = fopen("temporary.txt", "r");  // original file will be overwritten
    q = fopen(argv[1], "w");

    if(p == NULL || q == NULL)
    {
        printf("ERROR! Unable to open file\n");
        exit(1);
    }

    while((c = getc(p)) != EOF)         //removes trailing spaces/tabs, also replaces two or more white space by a single space.
    {
        whiteSpacing();
    }

    remove("temporary.txt");

    printf("Text in \"%s\" was formatted and overwritten.\n", argv[1]);
    fclose(p);
    fclose(q);

    return 0;
}
