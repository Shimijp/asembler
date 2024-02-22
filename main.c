
#include "globals.h"
#include "binary.h"
#include "files.h"
#include "linked_list.h"

int main(int argc , char ** argv)
{
	FILE *fp;
	char * str;
	node *head;
    node *temp;
    temp=head;

	fp=open_file("HELLO");
	init_str(&str,MAX_LINE_SIZE);
	while(fscanf(fp,"%s",str)!=EOF)
	{
        add_first(&temp,str);
        printf("%s\n",str);
        temp=temp->next;

	
	}
    temp=&head;
	print_list(&temp);
	
	fclose(fp);
	

    	return 0;
}


