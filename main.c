


#include "binary.h"
#include "macros.h"
int main(int argc , char ** argv)
{
	char * temp,c;
	int i;
	FILE *fp;
	node * list;
	macro * table;
    const char* instructions[] = {
            "mov",
            "cmp",
            "add",
            "sub",
            "not",
            "clr",
            "lea",
            "inc",
            "dec",
            "jmp",
            "bne",
            "red",
            "prn",
            "jsr",
            "rts",
            "hlt"
    };

	init_str(&temp,MAX_LINE_SIZE);

    fp=rewrite_macros(  "C:\\Users\\shimon2\\CLionProjects\\asembler2\\x");




	free(temp);
<<<<<<< HEAD
    fclose(fp);


=======
	fclose(fp);
	
	printf("Hello World!");
>>>>>>> 1006781594da27ccc09b2b89b07a97a45ef26d39









    return 0;
}


