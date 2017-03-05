#ifndef __FORMATTING_H__
#define __FORMATTING_H__

void whiteSpacing(FILE *outfile, char *line, int lineLength);
void lineWrapping(FILE *infile, FILE *outfile);
void matchPattern(FILE *file, char *pattern);
void stats(FILE *file);

#endif
