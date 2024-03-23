


#include "binary.h"
#include "macros.h"
int main(int argc , char ** argv)
{
	char * temp,c;
	int i;
	FILE *fp;
	node * list;
	macro * table;


	init_str(&temp,MAX_LINE_SIZE);

    fp=rewrite_macros(  "C:\\Users\\shimon2\\CLionProjects\\asembler2\\x");




	free(temp);

    fclose(fp);












    return 0;
}


