

#include "binary.h"
#include "macros.h"
int main(int argc , char ** argv)
{
	char * temp;
	int i;
	FILE *fp;
	node * list;
	
	
	
	
	init_str(&temp,MAX_LINE_SIZE);
	for(i=1;i<argc;i++)
	{
		fp=open_file(argv[i]);
		while(fgets(temp,MAX_LINE_SIZE,fp)!=NULL)
		{
			printf("%s\n",temp);
		
		}
	
	
	}
	rewind(fp);
	list=get_macros_names(fp);
	print_list(list);
	free(temp);
	fclose(fp);
	


     return 0;
}


