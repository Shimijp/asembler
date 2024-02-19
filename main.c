//
// Created by shimon2 on 19/02/2024.
#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

int main(int argc , char ** argv)
{

    bool flag;
    char * res=dec_to_bin(  -1, 14);
    printf("in binary: %s\n",res);
    flag=two_com(res);
    printf("in binary: %s\n",res);

    return 0;
}


