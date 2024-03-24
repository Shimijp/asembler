

#ifndef ASEMBLER2_GLOBALS_H
#define ASEMBLER2_GLOBALS_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "linked_list.h"


#define REG_NAME_SIZE 2
#define FIRST_ROW 100
#define  MAX_ROW 4095
#define GROUPS 3
#define MAX_GROUP_SIZE 9
#define


#define NONE_EXIST (-1)
#define CMD_SIZE 3
#define WORD_SIZE 14
#define MAX_WORDS 5
typedef enum
{
    mov,
    cmp,
    add,
    sub,
    not,
    clr,
    lea,
    inc,
    dec,
    jmp,
    bne,
    red,
    prn,
    jsr,
    rts,
    hlt,
    INVALID=-1
}optcode;
static const char* instructions[] = {
        "mov",
        "cmp",
        "add",
        "sub",
        "not",
        "clr",
        "lea",
        "inc",
        "dec",
        "jmp",
        "bne",
        "red",
        "prn",
        "jsr",
        "rts",
        "hlt"
};
static const optcode opcode_matrix[3][MAX_GROUP_SIZE] = {
        {mov, cmp, add, sub, lea, INVALID, INVALID, INVALID, INVALID}, // First group
        {not, clr, inc, dec, jmp, bne, red, prn, jsr}, // Second group
        {rts, hlt, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID} // Third group
};

typedef enum
{
    A,R,E
}ARE;



typedef enum bool
{
        false,
        true
}bool;
typedef enum
{
    r0,r1,r2,r3,r4,r5,r6,r7

}registers;



typedef enum
{
    imidiate_a,
    direct_a,
    per_index,
    direct_reg

}address;
typedef struct
{
     optcode d_optcode;
     char cmd_name[CMD_SIZE];
}command;








#endif 
