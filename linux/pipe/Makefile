all: pipe pipe1 pipe2 pipe3
pipe3: pipe3.o
	gcc -o pipe3 pipe3.o

pipe3.o: pipe3.c
	gcc -o pipe3.o -c pipe3.c

pipe2: pipe2.o
	gcc -o pipe2 pipe2.o

pipe2.o: pipe2.c
	gcc -o pipe2.o -c pipe2.c

pipe: pipe.o
	gcc -o pipe pipe.o

pipe.o: pipe.c
	gcc -o pipe.o -c pipe.c

pipe1: pipe1.o
	gcc -o pipe1 pipe1.o

pipe1.o: pipe1.c
	gcc -o pipe1.o -c pipe1.c

clean:
	rm *.o
