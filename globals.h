//
// Created by shimon2 on 19/02/2024.
//

#ifndef ASEMBLER2_GLOBALS_H
#define ASEMBLER2_GLOBALS_H
#define REG_NAME_SIZE 2
#define  MEMORY_SIZE 4096
#define MAX_BIT 8192
#define INVALID (-1)
#define CMD_SIZE 3
#define WORD_SIZE 14

typedef enum
{
        false,
        true,


}bool;
typedef enum
{
    r0,r1,r2,r3,r4,r5,r6,r7

}registers;
typedef struct
{
    int ARE :2;
    int word_s:WORD_SIZE;

}word;
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

}optcode;

typedef enum
{
    imidiate_a,
    direct_a,
    per_index,
    direct_reg,

}address;
typedef struct
{
     optcode d_optcode;
    char cmd_name[CMD_SIZE];
}command;







#endif //ASEMBLER2_GLOBALS_H
