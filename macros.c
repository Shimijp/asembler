#include "macros.h"


node * get_macros_from_file(FILE * fp)
{

    node * temp;
    char * str;


    temp=NULL;
    init_str(&str,MAX_LINE_SIZE);

    while(fgets(str,MAX_LINE_SIZE,fp)!=NULL)
    {
        if(strstr(str,MCR))
        {
            /*todo*/
        }
    }

}
char * get_mcr_name(char * line)
{
    char * name;
    /*todo*/
}


