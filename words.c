

#include "words.h"
int count_words(char * line)
{
    int i,len,count;
    i=count=0;
    if(is_empty_line(line))
    {
        return 0;
    }
    len= strlen(line);
    for(i=0;i<len,line[i];i++)
    {
        if(line[i]==' ')
        {
            count++;
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
    int count,i,j,k,len;
    count = count_words(line);
    if(count<=0)
    {
        return NULL;
    }
    arr=(char **)malloc((count+1)*sizeof(char *));
    check_malloc((void*)arr);
    i=0;
    for(i=0;i<count;i++)
    {
        init_str(&arr[i],MAX_LINE_SIZE);
    }
    i=j=k=0;
    len=strlen(line);

    for(;i<count;i++)
    {
        if(!is_empty_line(line))
        {
            strcpy(arr[k++], get_first_word(line));
            line+= strlen(arr[k-1])+1;
        }

    }

    return arr;





}
bool is_empty_line(const char * line)
{

    return line[0]=='\n';
}
char * clear_word(char * command)
{
    char * res;
    int len;
    len= strlen(command);
    init_str(&res,len-1);
    if(command[len-1]==':' || command[len-1]==',')
    {
        strncpy(res,command,len-1);
        return res;
    }
    else
    {
        free(res);
        return command;

    }


}