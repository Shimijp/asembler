#include <stdlib.h>
#include "globals.h"
#include "memory.h"

typedef struct node
{
	char * str;
	struct node * next;



}node;

bool init_node(node **ptr);
void add_first(node ** ptr, char * str);
void add_last(node ** ptr, char * str);
void delete_val(node ** ptr, char * val);
int find_val(node ** ptr , char *str);
void delete_head(node ** ptr);
void print_list(node ** ptr);

