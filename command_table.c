

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