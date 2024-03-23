


#include "binary.h"
#include "macros.h"
#include "mdefine.h"
int main(int argc , char ** argv)
{
	char * temp,c;
	int i;
	FILE *fp;
	node * list;
	macro * table;


	init_str(&temp,MAX_LINE_SIZE);

    fp =rewrite_macros(  "/Users/talaverbuch/CLionProjects/asembler/x");

    printf("%d\n",fp==NULL);
    while(fgets(temp,MAX_LINE_SIZE,fp)!=NULL)
    {
        printf("%s",temp);
    }

    rewind(fp);
    get_signs(fp);


	free(temp);

    fclose(fp);












    return 0;
}


