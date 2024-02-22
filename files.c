

#include "files.h"

FILE * open_file(char * path)
{
    FILE *fp;
    fp= fopen(path, "r+");
    if(!check_file(fp))
    {
        perror("error!");
        exit(EXIT_FAILURE);
    }
    return fp;

}
bool check_file(FILE *fp)
{

	return fp != NULL;
}
