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
	char * str;
	macro *table;
	node * mcr_list;
	int  length,name_length, index;
	bool flag;
	
	
	mcr_list=NULL;
	mcr_list=get_macros_names(fp);
	length=get_length(&mcr_list);
	table=(macro*)malloc(length*sizeof(macro));
	init_str(&str,MAX_LINE_SIZE);
	
	while(fscanf(fp,"%s",str)!=EOF)
	{
		flag=false;
		if(!strcmp(str,MCR))
		{
			fscanf(fp,"%s",str);
			index=find_val(&mcr_list,str);
			init_str(&table[index-1].name,strlen(str));
			table[index-1].mcr_cmd=NULL;
			while(fgets(str,MAX_LINE_SIZE,fp)!=NULL && !flag)
			{
				add_last(&table[index-1].mcr_cmd,str);
				if(strstr(str,END_MCR))
				{
					flag=true;
				
				}
			
			}
		
		}
	
	
	
	
	}
	return table;
	


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


