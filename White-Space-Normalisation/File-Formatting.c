#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "formatting.h"

char c;

int main(int argc, char *argv[])
{
    if(argc !=  3)
    {
        printf("Usage : %s Input-filename Output-filename\n", argv[0]);
        exit(-1);
    }

    //original file containing input
    FILE *infile = fopen(argv[1], "r");
    FILE *outfile = fopen(argv[2], "w");

    //error checking, also asks user if file is to be created.
    if(infile == NULL || outfile == NULL)
    {
        printf("Unable to open file %s\n", argv[1]);
        printf("Do you want to create %s file ? (Y/N)\n", argv[1]);

        c = getchar();
        if(c == 'y' || c == 'Y')
        {
            system("clear");
            infile = fopen(argv[1], "w");
            printf("Type here to write to the file\n");

            c = getchar();
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

    while((c = getc(infile)) != EOF)
    {
        lineWrapping(infile, outfile);
    }

    fclose(infile);
    fclose(outfile);

    printf("\n%s  was formatted to %s\n", argv[1], argv[2]);

    printf("\nEnable Stats For Nerds ? (Y/N)\n");
    c = getchar();
    if(c == 'y' || c == 'Y')
    {
        system("clear");
        outfile = fopen(argv[2], "r");
        stats(outfile);
        fclose(outfile);
    }
}
