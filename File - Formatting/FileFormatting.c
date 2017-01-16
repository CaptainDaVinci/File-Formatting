#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formatting.h"

char c;

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage : %s Input-filename Output-filename\n", argv[0]);
        exit(-1);
    }

    FILE *infile = fopen(argv[1], "r");                //original file containing input
    FILE *outfile = fopen(argv[2], "w");

    if(infile == NULL || outfile == NULL)          //error checking, also asks user if file is to be created.
    {
        printf("Unable to open file %s\n", argv[1]);
        printf("Do you want to create '%s' file ? (y/n)\n", argv[1]);

        c = getchar();
        if(c == 'y' || c == 'Y')
        {
            infile = fopen(argv[1], "w+");
            printf("Type here to write to the file\n");

            while((c = getchar()) != EOF)
            {
                putc(c, infile);
            }
            fclose(infile);

            infile = fopen(argv[1], "r");
        }

        else
        {
            fclose(outfile);
            remove(argv[2]);
            exit(1);
        }
    }

    while((c = getc(infile)) != EOF)   // for line wrapping
    {
        lineWrapping(infile, outfile);
    }

    fclose(infile);
    fclose(outfile);

    printf("'%s'  was formatted to  '%s'.\n", argv[1], argv[2]);
}
