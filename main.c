int *call();

#include "binary.h"
#include "macros.h"
int main(int argc , char ** argv)
{
	char * temp,c;
	int i;
	FILE *fp;
	node * list;
	macro * table;


	c=0;
	init_str(&temp,MAX_LINE_SIZE);
	for(i=1;i<argc;i++) {
        fp = open_file("C:\\Users\\shimon2\\CLionProjects\\asembler2\\x");

		while(!feof(fp))
		{
            fscanf(fp,"%s",temp);
            printf("%s\n",temp);



		}


	}
	rewind(fp);
	list=get_macros_names(fp);
	print_list(list);
	table=get_macros_from_file(fp);
    print_macro_table(table, 3);





	free(temp);
	fclose(fp);
	
	printf("Hello World!");








     return 0;
}


