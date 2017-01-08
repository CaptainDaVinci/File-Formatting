#define MAXLEN 65       //length for wrapping
#define MAXLINE 1000    // maximum length for one line

extern FILE *p;
extern FILE *q;

int getLine(char *, char);
void trim(char *);


void folding(char c)
{
    char line[MAXLINE];
    int len;
    while((len = getLine(line, c)) > 1) // proceed only if length of line is greater than 1
    {
        if(len > MAXLEN)
        {
            trim(line);
        }
        fprintf(q, "%s", line);
    }

}

int getLine(char line[], char c)
{
    int nc = 0;

    while(((c != EOF)) && c != '\n')
    {
        line[nc] = c;
        nc++;
        c = getc(p);
    }

    line[nc] = '\0';    //all characters of the file are stored in an array

    return nc;
}

void trim(char line[])
{
    int i = 0;
    int lastBlank = 0;
    int j = 1;

    for(i = 0; line[i] != '\0'; i++)
    {
        if(line[i] == ' ' || line[i] == '\t')   // kees track of the last whiteSpacing.
        {
            lastBlank = i;
        }

        if(i == MAXLEN * j)    //prints a new line at every MAXLEN interval
        {
            line[lastBlank] = '\n';
            j++;
        }
    }

    line[i] = '\n';
    line[i + 1] = '\0';
}
