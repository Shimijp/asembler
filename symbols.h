/*Tal Averbuch*/
#ifndef ASEMBLER2_SYMBOLS_H
#define ASEMBLER2_SYMBOLS_H

#include "globals.h"
#include "memory.h"
#include "files.h"

#define COLON ':'
#define MAX_LABEL_LENGTH 31 /*or 32 to include '\0'?*/
#define MAX_IDENTIFIER_LENGTH 11
#define IDENTIFIERS_NUM 5
#define INSTRUCTIONS_NUM 16

#define DATA ".data"
#define DEFINE ".define"
#define STRING ".string"
#define ENTRY ".entry"
#define EXTERN ".extern"
#define NONE "no identifier"

#define MDEFINE "mdefine"
#define MDATA "data"
#define CODE "code"
#define EXTERNAL "external"
#define RELOCATABLE "relocatable"


typedef struct sign {
    char v_name[MAX_LABEL_LENGTH]; /*variable name*/
    char identifier[MAX_IDENTIFIER_LENGTH];
    int val; /*variable values*/
    struct sign *next; /*pointer to next sign in the nested list*/
} sign;

static char *identifiers[] = {
        DATA,
        DEFINE,
        STRING,
        ENTRY,
        EXTERN,
        NONE
};

static char *properties[] = {
    MDEFINE,
    MDATA,
    RELOCATABLE,
    EXTERNAL,
    CODE,
};

bool add_first_sign(sign **ptr, char *name, char *identifier, int val);
bool v_name_exists(sign **ptr, char *name);
bool add_last_sign(sign **ptr, char *name, char *identifier, int val);
sign *get_signs(FILE *nfp); /* adds the constants that are declared with .define or with LABEL: */
void print_sign_table(sign * table);
char* get_identifier(char *line);
char* get_property(char *id); /* determines if mdefine/relocatable/external/code */

bool is_label(char *name); /* checks if the label name is legal */
bool is_sign(char *name); /* checks if the variable name is legal */
bool is_instruction(char *word); /* checks if a string is an opcode instruction */

FILE *rewrite_signs(char *name);
FILE *open_am_file(char *name);

sign *select_by_id(sign **ptr, char *id);
sign *select_by_name(sign **table, char *id);



#endif //ASEMBLER2_SYMBOLS_H
