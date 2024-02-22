//
// Created by shimon2 on 22/02/2024.
//

#ifndef ASEMBLER2_FILES_H
#define ASEMBLER2_FILES_H
#include "globals.h"
#endif //ASEMBLER2_FILES_H

FILE * open_file(char * path);
bool check_file(FILE *fp);
int count_lines(FILE *fp);
char ** copy_words(FILE *fp , int num_words);
