/*Tal Averbuch*/
#ifndef ASEMBLER2_MDEFINE_H
#define ASEMBLER2_MDEFINE_H

#include "globals.h"
#include "memory.h"
#include "files.h"

#define LABEL ":"
#define MAX_LABEL_LENGTH 31 /*or 32 to include '\0'?*/

#define DATA ".data"
#define DEFINE ".define"
#define STRING ".string"
#define ENTRY ".entry"
#define EXTERN ".extern"


typedef struct sign {
    char v_name[MAX_LABEL_LENGTH]; /*variable name*/
    int val; /*variable values*/
    struct sign *next; /*pointer to next sign in the nested list*/
} sign;

void add_first_sign(sign **ptr, char *name, int val);
bool v_name_exists(sign **ptr, char *name);
void add_last_sign(sign **ptr, char *name, int val);
sign *get_signs(FILE *nfp); /* adds the constants that are declared with .define or with LABEL: */
void print_sign_table(sign * table);



FILE *rewrite_signs(char *name);
FILE *open_am_file(char *name);

#endif //ASEMBLER2_MDEFINE_H
