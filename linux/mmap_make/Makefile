variables = mmap mmap1 mmap2 mmap3 mmap4 mmap5
all: $(variables)

mmap: mmap.o
	gcc -o mmap mmap.o

mmap.o: mmap.c
	gcc -o mmap.o -c mmap.c

mmap1: mmap1.o
	gcc -o mmap1 mmap1.o

mmap1.o: mmap1.c
	gcc -o mmap1.o -c mmap1.c

mmap2: mmap2.o
	gcc -o mmap2 mmap2.o

mmap2.o: mmap2.c
	gcc -o mmap2.o -c mmap2.c

mmap3: mmap3.o
	gcc -o mmap3 mmap3.o

mmap3.o: mmap3.c
	gcc -o mmap3.o -c mmap3.c

mmap4: mmap4.o
	gcc -o mmap4 mmap4.o

mmap4.o: mmap4.c
	gcc -o mmap4.o -c mmap4.c

mmap5: mmap5.o
	gcc -o mmap5 mmap5.o

mmap5.o: mmap5.c
	gcc -o mmap5.o -c mmap5.c

clean:
	rm *.o
