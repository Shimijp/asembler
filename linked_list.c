#include "linked_list.h"


void add_first(node ** ptr, char *tstr)
{

	node *temp;
    int len;
    len=strlen(tstr);
    if((*ptr)==NULL)
    {
        (*ptr)=(node*)malloc(sizeof(node));
        if((*ptr)!=NULL)
        {
            (*ptr)->str=(char*) malloc((len+1)*sizeof(char));
            strcpy((*ptr)->str,tstr);
            (*ptr)->next=NULL;
        }
        else
        {
            perror("not enough memory");
        }

    }
    else
    {
        temp=(node*)malloc(sizeof(node));
        if(temp!=NULL)
        {
            temp->str=(char*) malloc((len+1)*sizeof(char));
            temp->str=(char*) malloc((len+1)*sizeof(char));
            strcpy(temp->str,tstr);
            temp->next=NULL;
        }
        else
        {
            perror("not enough memory");
        }
    }

	
}
void add_last(node ** ptr, char * tstr) {

    node *temp;
    if((*ptr)==NULL)
    {
        add_first(ptr,tstr);
    }
    else
    {
        /*todo*/
    }


}
void print_list(node ** ptr)
{

	node *temp;
	temp=(*ptr);
	while(temp!= NULL)
	{
	
		printf("%s-->",temp->str);
		temp=temp->next;
	}

}
