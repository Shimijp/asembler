#include "macros.h"


node * get_macros_names(FILE * fp)
{

    node * temp;
    char *str;
   
    temp=NULL;
    init_str(&str,MAX_LINE_SIZE);
    
\
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

	node * temp;
	int length;
	macro* macro_list;

	temp=get_macros_name(fp);
	length=


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
			
	}
	else
	{
		return NULL;
	}
	
    
    
    
}


