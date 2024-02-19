#include <stdio.h>
#include <stdlib.h>
#define MAX_COMMAND 50
typedef struct node
{
    char word[MAX_COMMAND];
    struct node *next;
} node;
int check_empty(node * head);
node *add_first(char * word);
node*add_last(char *word,)

