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
        else
            temp = temp->next;
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
        fprintf(stderr,"Variable name '%s' already defined . Duplicate names are not allowed.\n", name);
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

sign *get_signs(FILE *nfp)
{
    sign *head_mdefine = NULL;
    sign **mdefine = &head_mdefine; /* the table that will hold all variables with int values in the file */

    char *first_word;
    char *line, v_name[MAX_LABEL_LENGTH];
    int val;

    init_str(&line, MAX_LINE_SIZE);
    while(fgets(line,MAX_LINE_SIZE,nfp) != NULL)
    {
        first_word = get_first_word(line);
        int fw_len = (int)strlen(first_word);
        if (strcmp(first_word, DEFINE) == 0)
        {
            line += (strlen(first_word) + 1);
            //first_word = get_first_word(line);
            if (sscanf(line, "%[^\n= ] = %d", v_name, &val) == 2)
            {
                printf("%s - %d\n", v_name, val);
                add_last_sign(mdefine, v_name, val);
            }

        }
        else if (fw_len > 1 && first_word[fw_len - 1] == ':' && first_word[fw_len - 2] != ' ')
        {
            strncpy(v_name, first_word, fw_len - 1);
            v_name[fw_len - 1] = '\0';
            printf("%s\n", v_name);
            add_last_sign(mdefine, v_name, 0); /*won't actually be zero, will hold value of the address*/
        }
    }
    free(first_word);
    rewind(nfp);
    return head_mdefine;
}

void print_sign_table(sign * table)
{
    sign * temp;
    temp=table;
    while(temp!= NULL)
    {
        printf("name: %s val: %d\n",temp->v_name,temp->val);
        temp=temp->next;
    }
    free(temp);
}


