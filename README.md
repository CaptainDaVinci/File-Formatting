# File-Formatting
A simple C program that takes input as text from a file, removes trailing and unnecessary blank spaces and also wraps the line after a given length.

## USAGE
compile and run the _main.c_ file as follows :
```
$ gcc main.c White-Spacing.c Statistics.c pattern-matching.c -o format
```
### To format a file.
```
$ ./format <Input file-name>  <Output file-name>
$ ./format in.txt out.txt           // in this case.
```
### To find a particluar pattern in a file.
```
$ ./format <file-name> find <string>
$ ./format in.txt Programming       // in this case.
```
### To view the statistics of a file.
```
$ ./format <file-name> stats
$ ./format in.txt stats             // in this case.
```

Here, "_in.txt_" is the example input file, and "_out.txt_" is the output file after formatting. Notice, in "_in.txt_" the text is widespread and not formatted properly.

After the program finishes running, have a look at the out.txt, notice that the formatting should have been improved. The file "_in.txt_" can contain any input and it would remove trailing white spaces and unnecessary white spaces between the words and also wraps line for you.

Here, "_in.txt_" and "_out.txt_" is just used as an example.
