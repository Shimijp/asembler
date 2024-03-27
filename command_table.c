

#include "command_table.h"
#include "globals.h"
#include "symbols.h"

bool is_symbole(char * command)
{
    return is_sign(command) || is_label(command);
}
int get_amount_of_op(char * command)
{
    optcode code;
    int i,j, res;
    code= get_optcode(command);
    res=-1;
    if(code>=0)
    {
        for(i=0;i<GROUPS;i++)
        {
            for(j=0;j<MAX_GROUP_SIZE,opcode_matrix[i][j]!=INVALID;j++)
            {
                if(code == opcode_matrix[i][j])
                {
                    res=opcode_matrix[i][j];
                }
            }
        }

    }
    if(res==0)
    {
        return 2;
    }
    else if(res==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}
registers get_s_reg(char * command)
{
    registers registers1;
    int i;
    for(i=0;i<=r7;i++)
    {
        if(!strcmp(command,reg[i]))
        {
            return i;
        }
    }
    return NON_REG;
}
optcode get_optcode(char * command)
{
    int i;
    for(i=0;i<=hlt;i++)
    {
        if(!strcmp(command,instructions[i]))
        {
            return i;
        }
    }
    return NONE_EXIST;
}
ARE get_are(char * command, sign ** table) {
    optcode code;
    registers regist;
    sign * res;

    code = get_optcode(command);
    regist= get_s_reg(command);
    res= select_by_name(table,command);
    if (code != NONE_EXIST || regist!= NON_REG || command[0]=='#') {/*if it's a code or a register or imitate address*/
        return A;
    }
    else
    {
        if(res==NULL)/*not a sign, return invalid value*/
        {
            return -1;
        }
        if(!strcmp(res->identifier,EXTERN))/*if it's an extarn value*/
        {
            return E;
        }
        if((!strcmp(res->identifier,MDEFINE) )|| (!strcmp(res->identifier,DATA))  )/*if it's a constant */
        {
            return A;
        }
        if(!strcmp(res->identifier,RELOCATABLE))/*if it's a relocatable address*/
        {
            return R;
        }
    }
    return -1;

}


