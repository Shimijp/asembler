

#include "words.h"
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
node * get_words(char * line)
{
    node * list;
    list=NULL;
    int j;
    char * word, c;
    init_str(&word,MAX_LINE_SIZE);
    j=0;
    c=line[j];
    while(c!='\0')
    {
        sscanf((line+j),"%s",word);
        j+=strlen(word)+1;
        c=line[j-1];
        add_last(&list,word);

    }
    return list;


}
char ** get_words_in_array(char * line)
{
    char ** arr;
    node * temp,*list;
    int count,i;
    list= get_words(line);

    count= get_length(&list);
    arr=(char **) malloc(sizeof(char*)*(count+1));
    check_malloc((void*)arr);
    temp=list;
    for(i=0;i<count;i++)
    {
        init_str(&(arr[i]),strlen(temp->str));
        strcpy(arr[i],temp->str);
        temp=temp->next;
    }
    free(list);
    return arr;
}
