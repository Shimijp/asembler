
#ifndef ASEMBLER2_COMMAND_TABLE_H
#define ASEMBLER2_COMMAND_TABLE_H
#include "globals.h"
#include "symbols.h"
#include "macros.h"
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
ARE get_are(char * line);
address get_s_address(char * line);
address get_d_address(char * line);
registers get_s_reg(char * line);
int get_amount_of_op(char * command);
bool is_data(char * command);





#endif //ASEMBLER2_COMMAND_TABLE_H
