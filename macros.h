#include "globals.h"
#include "memory.h"
#include "files.h"
#include "words.h"
#define MCR "mcr"
#define END_MCR "endmcr"
typedef struct
{
    char * name;
    node *mcr_cmd;
}macro;
void replace_macro(FILE * fp,macro *mcr);
node * get_macros_names(FILE * fp);
bool is_legal_macro(char * name);
macro * get_macros_from_file(FILE *fp );
void get_mcr_cmd(FILE * fp, macro * table);
void print_macro_table(macro * table , int size);
FILE * rewrite_macros(char * name);

void print_macros_to_file(FILE *fp,int num, macro * table);
int find_mcr_name(macro *table,char * name, int size);
bool check_macros(FILE *fp);