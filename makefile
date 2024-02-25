assembler: files.o binary.o linked_list.o memory.o main.o macros.o
	gcc -g -Wall -ansi -pedantic main.o files.o binary.o memory.o linked_list.o macros.o -o assembler
main.o: globals.h binary.h files.h memory.h linked_list.h main.c
	gcc  -c -g -Wall -ansi -pedantic main.c -o main.o
bianry.o: globals.h binary.h binary.c
	gcc -c -g -Wall -ansi -pedantic binary.c -o binary.o
files.o: globals.h files.h files.c
	gcc -c -g -Wall -ansi -pedantic files.c -o files.o
memory.o: globals.h memory.h
	gcc -c -g -Wall -ansi -pedantic memory.c -o memory.o
linked_list.o : globals.h memory.h linked_list.h
	gcc -c -g -Wall -ansi -pedantic linked_list.c -o linked_list.o

macros.o: macros.h globals.h linked_list.h macros.c
	gcc -c -g -Wall -ansi -pedantic macros.c -o macros.o
	

clean:
	rm *.o assembler
	



