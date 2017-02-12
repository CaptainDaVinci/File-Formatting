#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Formatting.h"

int main(int argc, char *argv[])
{
    char c;
    FILE *infile;
    FILE *outfile;

    if(argc !=  3 && argc != 4)
    {
        printf("Usage: %s <Input-filename> <Output-filename>\n\tOr\n", argv[0]);
        printf("Usage: %s <file-name> find <string>\n\tOr\n", argv[0]);
        printf("Usage: %s <file-name> stats\n", argv[0]);

        exit(-1);
    }

    if(strcmp(argv[2], "find") == 0)
    {
        infile = fopen(argv[1], "r");

        if(infile == NULL)
        {
            printf("error: unable to open file %s\n", argv[1]);
            exit(-1);
        }

        matchPattern(infile, argv[3]);
        fclose(infile);

        return 0;
    }

    if(strcmp(argv[2], "stats") == 0)
    {
        infile = fopen(argv[1], "r");

        if(infile == NULL)
        {
            printf("error: unable to open file %s\n", argv[1]);
            exit(-1);
        }

        stats(infile);
        fclose(infile);

        return 0;
    }

    //original file containing input
    infile = fopen(argv[1], "r");
    outfile = fopen(argv[2], "w");

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

            while((c = getchar()) != EOF)
                putc(c, infile);

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

    // edit the file.
    lineWrapping(infile, outfile);

    fclose(infile);
    fclose(outfile);

    printf("%s  was formatted to %s\n", argv[1], argv[2]);
}
