#include "globals.h"
#include "memory.h"
#include "files.h"
#include "linked_list.h"
#define MCR "mcr"
#define END_MCR "endmcr"
typedef struct
{
    char * name;
    node *mcr_cmd;
}macro;
void replace_macro(FILE * fp,macro *mcr);
node * get_macros_names(FILE * fp);
bool is_legal_macro(macro mcr);
char * get_mcr_name(char * line);
macro * get_macros_from_file(FILE *fp );
void print_macro_table(macro * table , int size);
