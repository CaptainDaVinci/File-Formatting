# File-Formatting
A simple C program that takes input as text from a file, removes trailing and unnecessary blank spaces and also wraps the line after a given length.

## USAGE
compile and run the main.c file as follows :

`$ gcc main.c -o format`

`$ ./format in.txt out.txt`

Here, "in.txt" is the example input file, and "out.txt" is the output file after formatting. Notice, in "in.txt" the text is widespread and not formatted properly.

After, compiling and running the code you will be asked if you would like to view the stats such as number of words, vowels, lines and also the longest word.
Press 'y' if you would like to view those stats.

After the program finishes running, have a look at the out.txt, notice that the formatting should have been improved. The file "in.txt" can contain any input and it would remove trailing white spaces and unnecessary white spaces between the words and also wraps line for you.

Here, "in.txt" and "out.txt" is just used as an example.
