/* Tal Averbuch */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "globals.h"
#include "files.h"
#include "memory.h"
#include "symbols.h"
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

void add_first_sign(sign **ptr, char *name,char *identifier, int val)
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
        strcpy(new_sign->identifier, identifier);
        new_sign->val = val;
        new_sign->next = *ptr; /* Point to the old first node */
        *ptr = new_sign; /* Update the head to the new node */
    }
}

void add_last_sign(sign **ptr, char *name, char *identifier, int value)
{
    if (v_name_exists(ptr, name))
    {
        fprintf(stderr,"Variable name '%s' already defined . Duplicate names are not allowed.\n", name);
        exit(EXIT_FAILURE);
    }
    /* add check if label with the same name already exists */
    if ((*ptr) == NULL)
    {
        add_first_sign(ptr, name, identifier, value);
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
        strcpy(temp->identifier, identifier);
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
                add_last_sign(mdefine, v_name, MDEFINE, val);
            }

        }
//        else if (fw_len > 1 && first_word[fw_len - 1] == ':' && first_word[fw_len - 2] != ' ')
        else if (is_label(first_word))
        {
            strncpy(v_name, first_word, fw_len - 1);
            v_name[fw_len - 1] = '\0';
            printf("%s\n", v_name);
            add_last_sign(mdefine, v_name, "\0", 0); /*won't actually be zero, will hold value of the address*/
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

bool is_label(char *name) {
    int len = (int)strlen(name);
    if (len > 1 && len <= MAX_LABEL_LENGTH)
    {
        if (name[len-1] == COLON && name[len-2] != ' ')
        {
            if(isalpha(name[0]))
            {
                for(int i = 1; i <= len-2; i++)
                {
                    if (!(isalpha(name[i]) || isdigit(name[i])))
                    {
                        fprintf(stderr, "not a legal label name\n");
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

char get_identifier(char *line)
{
    for (int i = 0; i < IDENTIFIERS_NUM; i++)
    {
        if(strcmp(get_first_word(line), identifiers[i]) == 0)
            return *identifiers[i];
        else if (is_label(get_first_word(line))) {
            if(strcmp(get_next_word(line), identifiers[i]) == 0)
                return *identifiers[i];
        }
    }
    return *identifiers[IDENTIFIERS_NUM];
}


//bool compare_ignore_whitespace(const char *line, const char *identifier) {
//    while(*line && *identifier) {
//        while(isspace((unsigned char)*line)) line++;
//        if(*line != *identifier) {
//            return false; /* does not match */
//        }
//        line++;
//        identifier++;
//    }
//    return *identifier == '\0' && !isalpha((unsigned char)*line) ? true : false;
//}