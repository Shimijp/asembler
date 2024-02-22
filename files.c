//
// Created by shimon2 on 22/02/2024.
//
#include "globals.h"
#include "files.h"

FILE * open_file(char * path)
{
    FILE *fp;
    fp= fopen(path, "w+");
    if(!check_file(fp))
    {
        perror("error!");
        exit(EXIT_FAILURE);
    }
    return fp;

}
