extern char c;

// replaces one or more blank spaces by a single space
void whiteSpacing(FILE *outfile, char *line, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        while(isblank(line[i]))
        {
            i++;
            if(!(isblank(line[i])) && line[i] != EOF)
                    putc(' ', outfile);
        }

        putc(line[i], outfile);
    }
}
