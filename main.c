
#include "globals.h"
#include "binary.h"
#include "files.h"
#include "linked_list.h"

int main(int argc , char ** argv)
{
	char * temp;
	int i;
	FILE *fp;
	
	init_str(&temp,MAX_LINE_SIZE);
	for(i=1;i<argc;i++)
	{
		fp=open_file(argv[i]);
		while(fgets(temp,MAX_LINE_SIZE,fp)!=NULL)
		{
			printf("%s\n",temp);
		
		}
	
	free(temp);
	fclose(fp);
	}
	


     return 0;
}


