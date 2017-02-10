#define MAXLEN 65       //length for wrapping
#define MAXLINE 1000    // maximum length for one line
extern char c;

int getLine(FILE *infile, FILE *outfile, char *line);
void wrap(char *line);

void lineWrapping(FILE *infile, FILE *outfile)
{
    char line[MAXLINE];
    int len;

    // proceed only if length of line is greater than 1
    while((len = getLine(infile, outfile, line)) > 1)
    {
        // wrap the line only if length of line is greater than the MAXLEN.
        if(len > MAXLEN)
        {
            wrap(line);
        }

        whiteSpacing(outfile, line, len);
    }

}

int getLine(FILE *infile, FILE *outfile, char line[])
{
    int nc = 0;

    // store each character of a line in an array.
    while(((c != EOF)) && c != '\n' && nc < MAXLINE - 2)
    {
        line[nc] = c;
        nc++;
        c = getc(infile);
    }

    if(c == '\n')
    {
        line[nc] = '\n';
        c = getc(infile);
    }

    line[nc + 1] = '\0';
    return nc + 1;
}

void wrap(char line[])
{
    int i = 0;
    int lastBlank = 0;
    int j = 1;

    for(i = 0; line[i] != '\0'; i++)
    {
        // kees track of the last white Spacing.
        if(isspace(line[i]))
        {
            lastBlank = i;
        }

        // kees track of the last white Spacing.
        if(i == MAXLEN * j)
        {
            line[lastBlank] = '\n';
            j++;
        }
    }

    line[i + 1] = '\0';
}
