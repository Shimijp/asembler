#include "memory.h"


bool check_malloc(void * ptr)
{
	bool res;
	res=ptr!=NULL;
	if(!res)
	{
		perror("not enough memory");
		
	}
	return res;
}
bool init_str(char **str, int length)
{

    (*str)=(char*)malloc((length+1)*sizeof(char));
	return check_malloc((void *)str);

}
