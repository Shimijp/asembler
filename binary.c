


#include "memory.h"
#include "binary.h"
/* converts a decimal number to a binary with 13 bits and the 14-th is to check whether its negative or positive*/
char * dec_to_bin(int num , int bit_size)
{
    char * temp;
    int i;
    bool check;


    temp=(char*)malloc((bit_size+1)* sizeof(char ));
    /*check_malloc((void*)temp);*/
    i=bit_size-1;/* the end of the string*/
    check=num<0;/* if a negative or not*/


    if(check)
    {
        num*=-1;/* change to a positive number, later with  two's complement we will chane to a negative representation*/
    }
    while(num!= 0 || i>=0)/* while there are zeros or ones to add*/
    {

    /* a simple base change algo*/
        temp[i]=(char)(num%BASE_2+ZERO_CHAR);
        num/=BASE_2;
        i--;
    }
    temp[bit_size]='\0';
    if(check)
    {

        my_not(temp);
        add_one(temp);
    }
    return temp;

}
void  my_not(char * bin)
{
    int i;
    char c;

    for(i=0;bin[i];i++)
    {
        /*reversing all places*/
        reverse(&bin[i]);


    }

}
/* adding one to a binary number*/
bool  add_one(char * bin)
{
    int i, len;
    char add;
    bool success;
    success=false;
    len= strlen(bin);
    add=ONE_CHAR;
    for ( i=len-1;i>=0 && (!success );i--)
    {
        if(bin[i]==ZERO_CHAR)
        {

            success = true;
        }
        reverse(&bin[i]);
        
    }
    return success;
}
/* change one to zero and vice versa */
void reverse(char * bin)
{
    (*bin)==ZERO_CHAR?((*bin)=ONE_CHAR):((*bin)=ZERO_CHAR);
}
int bin_to_dec(char *bin)
{
    int i,res,sign,len,pow;
    len= strlen(bin);
    res=0;
    pow=1;
    if(bin[0]=='1')
    {
        sign=-1;
    }
    else
    {
        sign=1;
    }
    for(i=len-1;i>=1;i--)
    {
        res+=((bin[i]-'0')*pow);
        pow*=2;
    }
    return res*sign;
}
