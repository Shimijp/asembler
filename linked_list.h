#include <stdlib.h>
#include "globals.h"
#include "memory.h"

typedef struct node
{
	char * str;
	struct node * next;



}node;

/*add to the beginning of the list*/
void add_first(node ** ptr, char * str);
/* add at the end of the list*/
void add_last(node ** ptr, char * str);
/*delete a specific value from the list*/
void delete_val(node ** ptr, char * val);
/* find a specific value int a list ,return the index of the value or -1 if nor found*/
int find_val(node ** ptr , char *str);
/* delete the head of the list that  are passed*/
void delete_head(node ** ptr);
/* print the values of the list*/
void print_list(node * ptr);
/* return the length of the list, if empty returns zero*/
int get_length(node ** ptr );
