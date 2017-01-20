#include <ctype.h>

extern char c;

void whiteSpacing(FILE *infile, FILE *outfile, char *line, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        while(isblank(line[i]))
        {
            //printf("%d ", i);
            i++;
            if(!(isblank(line[i])) && line[i] != EOF)
                    putc(' ', outfile);
        }

        putc(line[i], outfile);
    }
    // while(isblank(c))   //replaces two or more spaces by a single space
    // {
    //     c = getc(infile);
    //     if (!(isspace(c)) && c != EOF)
    //         putc(' ', outfile);
    //
    // }
    // putc(c, outfile);
}
