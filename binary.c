//
// Created by shimon2 on 19/02/2024.
//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary.h"

char * dec_to_bin(int num , int bit_size)
{
    char * temp;
    int i;
    bool check;


    temp=(char*)malloc((bit_size+1)* sizeof(char ));
    i=bit_size-1;
    check=num<0;
    if(check)
    {
        num*=-1;
    }

    while(num!= 0 || i>=0)
    {


        temp[i]=(char)(num%BASE+ZERO_CHAR);
        num/=BASE;
        i--;
    }
    temp[bit_size]='\0';
    if(check)
    {
        two_com(temp);
        add_one(temp);
    }
    return temp;

}
bool  two_com(char * bin)
{
    int i;
    char c;
    bool success;

    success=false;

    c=bin[0];

    for(i=0;bin[i];i++)
    {
        /*reversing all places*/
        revrse(&bin[i]);


    }
    /*if(c==ONE_CHAR)
    {
        success=add_one(bin);
    }
    else
    {
        success=true;
    }*/
    return true;


}
bool  add_one(char * bin)
{
    int i, len;
    char add;
    bool success;

    success=false;
    len= strlen(bin);
    add=ONE_CHAR;

    for ( i=len-1;i>=0 && (!success );i++)
    {
        if(bin[i]==ZERO_CHAR)
        {

            success = true;
        }
        revrse(&bin[i]);


    }
    return success;
}

void revrse(char * bin)
{
    (*bin)==ZERO_CHAR?((*bin)=ONE_CHAR):((*bin)=ZERO_CHAR);
}