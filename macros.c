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
	int  length, index;


    /*creating a  table of all the macros in the file so that there is name and list for all thor commands*/
	mcr_list=NULL;
    /* getting the macros names in a list*/
	mcr_list=get_macros_names(fp);
    /* getting the length of the list*/
	length=get_length(&mcr_list);
    /*initializing the string to scan to*/
    init_str(&str,MAX_LINE_SIZE);
    if(length<=0)
    {
        return NULL;
    }
	table=(macro*)malloc((length+1)*sizeof(macro));
	index=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s",str);

        if(!strcmp(str,MCR))
        {

            get_mcr_cmd(fp,&table[index]);
            index++;

        }
    }


    free(mcr_list);
    free(str);
    rewind(fp);
	return table;


}

void get_mcr_cmd(FILE * fp , macro *table)
{
    char * str;

    bool flag;
    init_str(&str,MAX_LINE_SIZE);

    flag=true;

    fscanf(fp,"%s",str);
    init_str(&(table->name),strlen(str));
    strcpy(table->name,str);
    table->mcr_cmd=NULL;

        while((fgets(str,MAX_LINE_SIZE,fp)!=NULL) && flag)


            {
                if(!strstr(str,END_MCR))
                {

                    add_last(&(table->mcr_cmd),str);

                }
                else
                {
                    flag=false;
                }

            }

    fseek(fp,(long)((-1)*strlen(str)),SEEK_CUR);

}
FILE * rewrite_macros(char * name)
{
    FILE * fp,*nfp;
    node * names;
    char *new_name,*str, *res;
    int new_len,table_len, i;
    macro * table;


    /* creating the .am file*/
    new_len=(strlen(name)+strlen(".am"));
    init_str(&new_name,new_len);
    strcpy(new_name,name);
    strcat(new_name,".am");
    fp=open_file(name);

    /*now, check if all macros names are legal, if not an error message will apeer with line number*/
    check_macros(fp);

    init_str(&str,MAX_LINE_SIZE);
    names= get_macros_names(fp);
    table=get_macros_from_file(fp);
    table_len= get_length(&names);


    nfp=fopen(new_name,"w+");
    str=fgets(str,MAX_LINE_SIZE,fp);
    while(str!=NULL)
    {
        res= get_first_word(str);
        i= find_mcr_name(table,res,table_len);
        if(i<0 && strcmp(res,"mcr")!=0)
        {
            fprintf(nfp,"%s",str);
        }
        else if(i>=0)
        {
            while(table[i].mcr_cmd!=NULL)
            {
                fprintf(nfp,"%s",table[i].mcr_cmd->str);
                table[i].mcr_cmd=table[i].mcr_cmd->next;
            }
        }else if(!strcmp(res,"mcr"))
        {
            while(strcmp("endmcr",res)!=0)
            {
                str= fgets(str,MAX_LINE_SIZE,fp);
                res= get_first_word(str);
            }
        }
        str= fgets(str,MAX_LINE_SIZE,fp);




    }
    free(names);
    free(new_name);
    free(str);
    rewind(fp);
    fclose(fp);
    rewind(nfp);


    return nfp;

}


void print_macro_table(macro * table , int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        printf("name: %s",table[i].name);
        print_list(table[i].mcr_cmd);
    }


}
char * get_first_word(char * line)
{
    int i , j , len;
    char * res,c;
    i=j=0;
    init_str(&res,MAX_LINE_SIZE);

    strcpy(res,line);

    while(isspace(*res) && *res!='\0')
    {
        i++;
        res++;
    }
    j=i;
    while(!isspace(res[j]) && res[j]!= '\0')
    {
        j++;
    }
    res[j]='\0';

    return res;

}
int find_mcr_name(macro *table,char * name, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(!strcmp(table[i].name,name))
        {
            return i;
        }
    }
    return -1;

}
void check_macros(FILE * fp)
{
    char * line,*word;
    int i;
    init_str(&line,MAX_LINE_SIZE+1);
    i=0;
    while(fgets(line,MAX_LINE_SIZE,fp)!=NULL)
    {
        i++;
        word= get_first_word(line);
        /* if it is a macro definition*/
        if(!strcmp(word,MCR))
        {
            line+=(strlen(word)+1);/*move to the next word*/
            word= get_first_word(line);
            if(!is_legal_macro(word))/* search for macro name in table of commands*/
            {
                fprintf(stderr,"%s %s %d\n",word,"is not a legal macro name name, in line:", i);
                free(line);
                free(word);
                rewind(fp);
                exit(EXIT_FAILURE);
            }

        }

    }
    rewind(fp);


}
bool is_legal_macro(char * name)
{
    int i;
    for(i=0;i<=hlt;i++)
    {
        if(!strcmp(name,instructions[i]))
        {

            return false;
        }
    }
    return true;


}