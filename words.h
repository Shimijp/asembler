

#ifndef ASEMBLER2_WORDS_H
#define ASEMBLER2_WORDS_H
#include "globals.h"
#include "memory.h"
#include "linked_list.h"

#define MAX_LINE_SIZE 80
/*gets the first word in line, ignore white spaces*/
char * get_first_word(char * line);

/*gets the next word, to fix*/
char * get_next_word(char * line);
node * get_words(char * line);
/* gets all the words in a line in an array, a word is seperted bo space*/
char ** get_words_in_array(char * line);
/* return the amount of different words in line*/
int count_words(char * line);
/* check if a line is empty*/
bool is_empty_line(const char * line);
/* return a string without ',' or ':*/
char * clear_word(char * command);
#endif //ASEMBLER2_WORDS_H
