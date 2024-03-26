

#ifndef ASEMBLER2_WORDS_H
#define ASEMBLER2_WORDS_H
#include "globals.h"
#include "memory.h"
#include "linked_list.h"

#define MAX_LINE_SIZE 80
char * get_first_word(char * line);
char * get_next_word(char * line);
node * get_words(char * line);
char ** get_words_in_array(char * line);
bool is_empty_line(const char * line);
#endif //ASEMBLER2_WORDS_H
