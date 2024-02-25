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
macro get_macros_from_file(FILE *fp , char * mcr_name )
{
	char * str;
	macro mcr;
	int  name_length;
	
	length=strlen(mcr_name);
	
	init_str(&mcr.name,length);
	mcr.mcr_cmd=NULL;
	
	strcpy(mcr.name,mcr_name);
	
	
	
	
	
	
	str=(char*)malloc((strlen(temp->str)+1)*sizeof(char));
	while(fscanf(fp, "%s", str) != EOF)
	{
	
		if(!strcmp(str,CMP)
		{
			fscanf(fp,"%s",str)
			{
				if(
			
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
			
	}
	else
	{
		return NULL;
	}
	
    
    
    
}


