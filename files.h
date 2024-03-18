
#ifndef ASEMBLER2_FILES_H
#define ASEMBLER2_FILES_H

#include "globals.h"
#include "memory.h"


#define MAX_LINE_SIZE 80

/*goes through all  the arguments and attempt to open the files*/
void open_All_agrv(int argc,char ** argv);
/*open a single file*/
FILE * open_file(char * path);
/*check if a file exists or not , return a boolean vale*/
bool check_file(FILE *fp);
/*counts lines in a file*/
int count_lines(FILE *fp);
/* copy words in file to a array of string*/
char ** copy_words(FILE *fp , int num_words);

#endif 
