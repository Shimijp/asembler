#include "macros.h"



node * get_macros_names(FILE * fp)
{

    node * temp;
    char *str;
   
    temp=NULL;
    init_str(&str,MAX_LINE_SIZE);
    

     while(fscanf(fp,"%s",str)!=EOF)
     {
     
     	if(!strcmp(str,MCR))
     	{
     		fscanf(fp,"%s",str);
     		add_last(&temp,str);
     	
     	}
     
     
     }
     rewind(fp);
     
     return temp;
}
macro * get_macros_from_file(FILE *fp )
{
	char * str;
	macro *table;
	node * mcr_list;
	int  length,name_length, index;
	bool flag;

    /*creating a  table of all the macros in the file so that there is name and list for all thor commands*/
	mcr_list=NULL;
    /* getting the macros names in a list*/
	mcr_list=get_macros_names(fp);
    /* getting the length of the list*/
	length=get_length(&mcr_list);
	table=(macro*)malloc(length*sizeof(macro));
	init_str(&str,MAX_LINE_SIZE);
	index=0;
	while(fscanf(fp,"%s",str)!=EOF)
        {
            flag=true;
           if(!strcmp(str,MCR))
           {
               init_str(&table[index].name,strlen(str));
               strcpy(table[index].name,str);
               table[index].mcr_cmd=NULL;

               while(fscanf(fp,"%s",str)!=EOF && flag)
               {
                   flag= strcmp(str,END_MCR);
                   if(flag)
                   {
                       add_last(&(table[index].mcr_cmd),str);
                   }
                   else
                   {
                       add_last(&(table[index].mcr_cmd),"\n");
                   }
               }
           }

        }


	


}
char * get_mcr_name(char * line)
{
    char * name,c;
    int i;
    init_str(&name,MAX_LINE_SIZE);
    check_malloc((void*)name);
    i=0;
    if(isspace(line[i]))
	{
			
		while(isspace(c=line[i]))
		{
				i++;
		}
		strcpy(name,(line+i));
		return name;
			
	} else
	{
		return NULL;
	}

}

void print_macro_table(macro * table , int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        printf("name: %s",table[0].name);
        print_list(table[i].mcr_cmd);
    }


}
