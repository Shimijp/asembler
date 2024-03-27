

#include "words.h"
int count_words(char * line)
{
    int i,len,count;
    i=count=0;
    /* if an empty line , return zero*/
    if(is_empty_line(line))
    {
        return 0;
    }
    /* else, the length ogf the line*/

    /* count spaces that separates words*/
    for(i=0;line[i];i++)
    {
        if(line[i]==' ' )
        {
            count++;

            while(isspace(line[i]) || line[i]==',')
            {
                i++;
            }
        }

    }
    return (count+1);
}

char * get_first_word(char * line)
{
    int i , j , len;
    char * res,c;
    i=j=0;
    init_str(&res,MAX_LINE_SIZE);

    strcpy(res,line);
    /* move to a first non-white space char*/
    while(isspace(*res) && *res!='\0')
    {
        i++;
        res++;
    }
    j=i;
    /*now move to the end of the word*/
    while(!isspace(res[j])  && res[j]!= '\0' )
    {
        j++;
    }


    res[j]='\0';


    return res;

}
/*todo*/
char * get_next_word(char *line)
{
    char * word;
    word= get_first_word(line);/* gets the first word of the line*/
    line+=(strlen(word)+1);/* moves */

    return get_first_word(line);
}

char ** get_words_in_array(char * line)
{
    char ** arr,*token;
    int count,i,k,len;
    count = count_words(line);
    if(count<=0)
    {
        return NULL;
    }
    /* initializing the memory for array*/
    arr=(char **)malloc((count+1)*sizeof(char *));
    check_malloc((void*)arr);
    i=0;
    for(i=0;i<count;i++)
    {
        init_str(&arr[i],MAX_LINE_SIZE);
    }
    i=k=0;
    len=strlen(line);

    for(;i<count;i++)
    {
        if(!is_empty_line(line))

        {
            /*copying all the words to an indecis in the array and moving the line pointer*/
            token= get_first_word(line);
            if(!is_empty_line(token))
            {
                strcpy(arr[k++], token);
            }
            line+= strlen(arr[k-1])+1;
        }

    }

    return arr;





}
bool is_empty_line(const char * line)
{

    return line[0]=='\n' ;
}
char * clear_word(char * command)
{
    char * res;
    int len;
    len= strlen(command);
    init_str(&res,len);

    if(command[len-1]==':' || command[len-1]==',' || command[len-1]=='\n')/*checking the last char and removing if necessary*/
    {
        strncpy(res,command,len-1);
        res[len]='\0';
        return res;
    }
    else
    {
        free(res);
        return command;

    }


}