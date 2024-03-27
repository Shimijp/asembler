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
    FILE *nfp, *tmp_fp ;
    sign *table, *define_table;
    char *new_name, *line;
    int new_len, table_len, num_of_words;
    node *words;

    /* create a .tmp file */
    new_len = (int)(strlen(name) + strlen(".tmp"));
    init_str(&new_name,new_len);
    strcpy(new_name,name);
    strcat(new_name,".tmp");
    nfp = open_am_file(name);

    init_str(&line,MAX_LINE_SIZE);

    table = get_signs(nfp);
    define_table = select_by_id(&table, MDEFINE);
    table_len = get_length_signs(&define_table);

    tmp_fp = fopen(new_name,"w+");
    line = fgets(line ,MAX_LINE_SIZE, nfp);
    while(line != NULL)
    {
        words = get_words(line);
        num_of_words = get_length(&words);
        int i, j;
        for (i = 0; i < num_of_words; i++)
        {
            for(j = 0; j < table_len; j++)
            {

            }

    }

    }

    /* FINISH !!!! */
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

bool add_first_sign(sign **ptr, char *name,char *identifier, int val)
{
    sign *new_sign = (sign *) malloc(sizeof(sign));

    if (new_sign == NULL) {
        perror("not enough memory");
        return false;
        //exit(EXIT_FAILURE);
    }
    else
    {
        strncpy(new_sign->v_name, name, MAX_LABEL_LENGTH - 1);
        new_sign->v_name[MAX_LABEL_LENGTH - 1] = '\0'; /* Ensure null termination */
        strcpy(new_sign->identifier, identifier);
        new_sign->val = val;
        new_sign->next = *ptr; /* Point to the old first node */
        *ptr = new_sign; /* Update the head to the new node */
        return true;
    }
}

bool add_last_sign(sign **ptr, char *name, char *identifier, int value)
{
    /* check if label or variable with the same name already exists */
    if (v_name_exists(ptr, name))
    {
        fprintf(stderr,"Variable or label name '%s' already defined . Duplicate names are not allowed.\n", name);
        return false;
        //exit(EXIT_FAILURE);
    }

    if ((*ptr) == NULL)
    {
        add_first_sign(ptr, name, identifier, value);
        return true;
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
            return false;
            //exit(EXIT_FAILURE);
        }
        temp = temp->next;
        strncpy(temp->v_name, name, MAX_LABEL_LENGTH -1);
        temp->v_name[MAX_LABEL_LENGTH - 1] = '\0';
        temp->val = value;
        strcpy(temp->identifier, identifier);
        temp->next = NULL;
        return true;
    }
}

sign *get_signs(FILE *nfp)
{
    sign *head_symbols = NULL;
    sign **symbols = &head_symbols; /* the table that will hold all variables with int values in the file */

    char *first_word;
    char *line, v_name[MAX_LABEL_LENGTH];
    char *id;
    int val, i;
    bool flag = true;

    init_str(&line, MAX_LINE_SIZE);
    i = 0;
    while(fgets(line,MAX_LINE_SIZE,nfp) != NULL)
    {
        i++;
        first_word = get_first_word(line);
        int fw_len = (int)strlen(first_word);
        if (strcmp(first_word, DEFINE) == 0)
        {
            line += (strlen(first_word) + 1);
            if (sscanf(line, "%[^\n= ] = %d", v_name, &val) == 2)
            {
                if (is_sign(v_name))
                {
                    id = get_property(DEFINE);

                    if (!add_last_sign(symbols, v_name, id, val))
                    {
                        flag = false;
                        //fprintf(stderr, "Variable was not added to symbol table, line %d\n", i);
                    }
                }
                else
                    flag = false;
                    //fprintf(stderr, "Illegal variable name, line %d\n", i);
            }
            else {
                flag = false;
                fprintf(stderr, "error in variable definition, line %d\n", i);
            }

        }

        else if (is_label(first_word))
        {
            strncpy(v_name, first_word, fw_len - 1);
            v_name[fw_len - 1] = '\0';
            id = get_property(get_identifier(line));

            /*won't actually be zero, will hold value of the address*/
            if (!add_last_sign(symbols, v_name, id, 0))
            {
                flag = false;
                fprintf(stderr, "Label was not added to symbol table, line %d\n", i);
            }
        }
        else if (!is_instruction(first_word) && strcmp(line, "\n") != 0)
        {
            flag = false;
            fprintf(stderr, "Illegal label name, line %d\n", i);
        }

    }
    free(first_word);
    rewind(nfp);
    print_sign_table(head_symbols);
    if (!flag)
        exit(EXIT_FAILURE);
    return head_symbols;
}

void print_sign_table(sign *table)
{
    sign *temp;
    temp = table;
    while(temp!= NULL)
    {
        printf("name: %s, id: %s, val: %d\n",temp->v_name,temp -> identifier, temp->val);
        temp = temp->next;
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

bool is_sign(char *name)
{
    int len = (int)strlen(name);
    if (len > 1 && len <= MAX_LABEL_LENGTH)
    {
        if(isalpha(name[0]))
        {
            for(int i = 1; i <= len-2; i++)
            {
                if (!(isalpha(name[i]) || isdigit(name[i])))
                {
                    fprintf(stderr, "not a legal variable name\n");
                    return false;
                }
            }
            return true;
        }

    }
    return false;
}

char* get_identifier(char *line)
{
    for (int i = 0; i < IDENTIFIERS_NUM; i++)
    {
        if(strcmp(get_first_word(line), identifiers[i]) == 0)
            return identifiers[i];
        else if (is_label(get_first_word(line))) {
            if(strcmp(get_next_word(line), identifiers[i]) == 0)
                return identifiers[i];
        }
    }
    return identifiers[IDENTIFIERS_NUM];
}

char* get_property(char *id)
{
    if (strcmp(id, DEFINE) == 0)
        return MDEFINE;
    else if (strcmp(id, STRING) == 0 || strcmp(id, DATA) == 0)
        return MDATA;
    else if (strcmp(id, ENTRY) == 0)
        return RELOCATABLE;
    else if (strcmp(id, EXTERN) == 0)
        return EXTERNAL;
    return CODE;
}

sign *select_by_id(sign **table, char *id)
{
    sign *selected_head = NULL;
    sign **selected_table = &selected_head;

    sign *current = *table;
    while (current != NULL)
    {
        if (strcmp(current->identifier, id) == 0)
        {
            add_last_sign(selected_table, current->v_name, current->identifier, current->val);
        }
        current = current->next;
    }
    return selected_head;
}

bool is_instruction(char *word) {
    for (int i = 0; i < INSTRUCTIONS_NUM; ++i) {
        if (strcmp(instructions[i], word) == 0) {
            return true;
        }
    }
    return false;
}

sign *select_by_name(sign **table, char *id)
{
    sign *selected_head = NULL;
    sign **selected_table = &selected_head;

    sign *current = *table;
    while (current != NULL)
    {
        if (strcmp(current->v_name, id) == 0)
        {
            add_last_sign(selected_table, current->v_name, current->identifier, current->val);
        }
        current = current->next;
    }
    return selected_head;
}

int get_length_signs(sign **ptr )
{
    sign *temp;
    int count;

    temp = (*ptr);
    count = 0;
    while(temp != NULL)
    {
        ++count;
        temp = temp->next;
    }
    return count;
}