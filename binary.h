//
// Created by shimon2 on 19/02/2024.
//

#ifndef ASEMBLER2_BINARY_H
#define ASEMBLER2_BINARY_H
#define BASE 2
#define ZERO_CHAR '0'
#define ONE_CHAR '1'

#include "globals.h"

char * dec_to_bin(int num , int bit_size);
void  two_com(char * bin);
int bin_to_dec(char *bin);
bool  add_one(char * bin);
void reverse(char * bin);



#endif //ASEMBLER2_BINARY_H
