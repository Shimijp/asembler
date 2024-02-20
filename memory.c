//
// Created by shimon2 on 20/02/2024.
//

#include "memory.h"

/* checks if malloc successes*/
bool check_malloc(void *ptr)
{
    bool res;
     res=ptr==NULL;
     if(res)
     {
         perror("not enough memory ");

     }
    return res;
}
/*checks if file exists*/
bool check_file(FILE *fp)
{
    return fp !=NULL;
}
