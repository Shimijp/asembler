
#ifndef ASEMBLER2_COMMAND_TABLE_H
#define ASEMBLER2_COMMAND_TABLE_H
#include "globals.h"
typedef struct
{

    ARE digit:2;
    address s_address:2;
    address d_address:2;
    optcode code:4;
    registers s_reg;
    registers d_reg;
    node * binary;
    char * instruc;
    int ic;







}word;
address get_s_add(char * line);
ARE get_are(char * line);
address get_d_add(char * line);
optcode get_optcode(char * line);
registers get_s_reg(char * line);
registers get_d_reg(char * line);
bool is_first_word(char * word);
bool is_symbol(char * word);


#endif //ASEMBLER2_COMMAND_TABLE_H
