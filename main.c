

#include "binary.h"
#include "macros.h"
int main(int argc , char ** argv)
{
	char * temp;
	int i;
	FILE *fp;
	node * list;
	macro * table;
	
	
	
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
	
	
	table =(macro*)malloc(2*sizeof(macro));
	table[0].name=(char*)malloc(4*sizeof(char));
	strcpy(table[0].name,"my_mcr");
	printf("name: %s\n ",table[0].name);
	
	free(temp);
	fclose(fp);
	


     return 0;
}


