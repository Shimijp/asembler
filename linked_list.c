#include "linked_list.h"


void add_first(node ** ptr, char *tstr)
{

	node *temp;
    int len;

    /* calculating the memory needed for thw additional node*/
    len=strlen(tstr);
    temp=*ptr;
    *ptr=(node *)malloc(sizeof(node));

    /*cechkinfg the allocation*/
    if(*ptr==NULL)
    {
        perror("not enough memory");
        exit(EXIT_FAILURE);

    }
    else
    {
        (*ptr)->str=(char*)malloc((len+1)* sizeof(char ));
        strcpy((*ptr)->str,tstr);
        (*ptr)->next=temp;
    }
}


void add_last(node ** ptr, char * tstr) {


    int len;
    node * temp;

    len= strlen(tstr);
    /* if ptr is null simply add the node as first*/
    if((*ptr)==NULL) {
        add_first(ptr, tstr);

    }
    /* go to the end of the list then add*/
    else
    {
        temp=(*ptr);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=(node*) malloc(sizeof(node));
        temp=temp->next;
        if(check_malloc((void*)temp))
        {
            temp->str=(char*) malloc((len+1)* sizeof(char));
            if(check_malloc((void*)temp->str))
            {
                strcpy(temp->str,tstr);

            }
        }
        temp->next=NULL;
    }

}
int find_val(node **ptr,char *tstr)
{
    node *temp;
    int i;
    /* check each node for its value , if there is a match return its "index"*/
    if((*ptr)!=NULL)
    {
        temp=(*ptr);
        i=1;
        while(temp!=NULL)
        {
            if(strcmp(temp->str,tstr)==0)
            {
                return i;
            }
            temp=temp->next;
            i++;
        }
    }
    return NONE_EXIST;

}
void delete_val(node ** ptr, char * val)
{
    int loc ,i;
    node * temp,*prev;
    temp=prev=(*ptr);

    loc= find_val(ptr,val);
    /* if the node to n=be deleted is the first, move the node to its next and delete the first*/
    if(loc==1) {


        (*ptr) = (*ptr)->next;
        free(temp);
    }
    /* if there is such a node and its not the first, move until found and delete it*/
    else if(loc>1)
    {

             for(i=1;i<loc;i++)
             {

                 prev=temp;
                 temp=temp->next;
             }
             prev->next=temp->next;
             free(temp);

    }




}

void delete_head(node ** ptr)
{
    node * temp;
    if((*ptr)!=NULL)
    {
        temp=(*ptr);
        temp->next=NULL;
        (*ptr)=temp->next;
        free(temp);
    }
}




void print_list(node * ptr)
{
	while(ptr != NULL)
	{

		printf("%s-->",ptr->str);
        ptr=ptr->next;
	}
    printf("%s\n","NULL");

}

int get_length(node ** ptr )
{
    node * temp;
    int count;

    temp=(*ptr);
    count=0;
    while(temp!=NULL)
    {
        ++count;
        temp=temp->next;
    }
    return count;
}