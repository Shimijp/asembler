/* Tal Averbuch */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"
#include "files.h"
#include "memory.h"
#include "mdefine.h"
#include "macros.h" /*to use get_first_word*/

FILE *open_am_file(char *name)
{
    FILE *nfp;
    int new_len;
    char *new_name;

    new_len = (int)(strlen(name) + strlen(".am"));

    init_str(&new_name,new_len);

    strcpy(new_name,name);
    strcat(new_name,".am");
    printf("%s\n",name);
    nfp = fopen(new_name, "w+");
    if(!check_file(nfp))
    {
        perror("error!");
        exit(EXIT_FAILURE);
    }
    free(new_name);
    return nfp;
}

FILE *rewrite_signs(char *name)
{
    FILE *nfp;
    sign *signs;
    return 0;
}

bool v_name_exists(sign **ptr, char *name)
{
    sign *temp = *ptr;
    while (temp != NULL)
    {
        if (strcmp(temp->v_name, name) == 0)
        {
            return true;
        }
    }
    return false; /* name doesn't exist */
}

void add_first_sign(sign **ptr, char *name, int val)
{
    sign *new_sign = (sign *) malloc(sizeof(sign));

    if (new_sign == NULL) {
        perror("not enough memory");
        exit(EXIT_FAILURE);
    }
    else
    {
        strncpy(new_sign->v_name, name, MAX_LABEL_LENGTH - 1);
        new_sign->v_name[MAX_LABEL_LENGTH - 1] = '\0'; /* Ensure null termination */
        new_sign->val = val;
        new_sign->next = *ptr; /* Point to the old first node */
        *ptr = new_sign; /* Update the head to the new node */
    }
}

void add_last_sign(sign **ptr, char *name, int value)
{
    if (v_name_exists(ptr, name))
    {
        printf("Variable name '%s' already exists in mdefine table. Duplicate names are not allowed.\n", name);
        exit(EXIT_FAILURE);
    }
    /* add check if label with the same name already exists */
    if ((*ptr) == NULL)
    {
        add_first_sign(ptr, name, value);
    }

    else
    {
        sign *temp = *ptr;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = (sign *)malloc(sizeof(sign));
        if (!check_malloc(temp->next))
        {
            exit(EXIT_FAILURE);
        }
        temp = temp->next;
        strncpy(temp->v_name, name, MAX_LABEL_LENGTH -1);
        temp->v_name[MAX_LABEL_LENGTH - 1] = '\0';
        temp->val = value;
        temp->next = NULL;
    }
}

sign get_constants(FILE *nfp)
{
    sign *mdefine; /* the table that will hold hold all variables with int values in the file */
    char *line, *first_word;

    mdefine = NULL;

    line = fgets(line,MAX_LINE_SIZE,nfp);
    while(line != NULL)
    {
        first_word = get_first_word(line);
        if (strcmp(first_word, DEFINE) == 0)
        {

        }
    }

}