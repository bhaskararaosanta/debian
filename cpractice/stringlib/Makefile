all: strcpy strcmp
strcmp: strcmp.o
	gcc -o strcmp strcmp.o

strcmp.o: strcmp.c
	gcc -o strcmp.o -c strcmp.c

strcpy: strcpy.o
	gcc -o strcpy strcpy.o

strcpy.o: strcpy.c
	gcc -o strcpy.o -c strcpy.c

clean:
	rm *.o
