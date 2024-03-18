

#include "files.h"


void open_All_agrv(int argc,char ** argv)
{
	int i;
	for(i=0;i<argc;i++)
	{
		open_file(argv[i]);
	}

}
FILE * open_file(char * path)
{
    FILE *fp;
    int new_len;
    char * name;
    
    new_len=strlen(path)+strlen(".as");

    init_str(&name,new_len);

    strcpy(name,path);
    strcat(name,".as");
    printf("%s\n",name);
    fp= fopen(name, "r+");
    if(!check_file(fp))
    {
        perror("error!");
        exit(EXIT_FAILURE);
    }
    free(name);
    return fp;

}
bool check_file(FILE *fp)
{

	return fp != NULL;
}
