//
// Created by shimon2 on 19/02/2024.
#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

int main(int argc , char ** argv)
{

    int num1;
    char * res=dec_to_bin(  -2, 14);
    printf("in binary: %s\n",res);
    two_com(res);
    printf("in binary: %s\n",res);

    return 0;
}


