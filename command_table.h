
#ifndef ASEMBLER2_COMMAND_TABLE_H
#define ASEMBLER2_COMMAND_TABLE_H
#include "globals.h"
#include "symbols.h"
#include "macros.h"
typedef struct table
{
    word ins;
    struct table * next;
}table;
/*void add_first_table(table ** pt,char * line );
void add_last_table(table ** pt,char * line);
unsigned int get_length_table(table ** pt);
int find_in_list(table ** pt, char * val);*/

/* gets the ARE symbols*/
ARE get_are(char * line,sign** table);
/*gets the address of a command*/
address get_s_address( char * command, sign ** table);
address get_d_address(char * command);
/* if the operand is a register then returns it*/
registers get_s_reg(char * command);
/*gets the amount of legal operands for the command*/
int get_amount_of_op(char * command);

char * convert_to_bin(char * command, sign ** table);
node * str_to_bin(char * data);
bool is_symbol(char * command);
optcode get_optcode(char * command);
sign * find_in_table(sign ** table, char * name );


#endif //ASEMBLER2_COMMAND_TABLE_H
