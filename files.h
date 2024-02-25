
#ifndef ASEMBLER2_FILES_H
#define ASEMBLER2_FILES_H

#include "globals.h"
#include "memory.h"


#define MAX_LINE_SIZE 80
#define END_TP ".as"

void open_All_agrv(int argc,char ** argv);
FILE * open_file(char * path);
bool check_file(FILE *fp);
int count_lines(FILE *fp);
char ** copy_words(FILE *fp , int num_words);

#endif 
