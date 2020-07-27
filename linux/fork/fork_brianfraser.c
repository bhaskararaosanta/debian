#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int i = 0;

void dosomework(char *name)
{
	int i;
	const int numoftimes = 5;
	for( ; i < numoftimes; i++) {
		sleep(rand() % 4);
		printf("Done pass:%d for %s\n", i, name);
	}
}

int main(int argc, char *argv[])
{
	printf("I am: %d\n", (int)getpid());

	/* pid_t fork(void); */
	pid_t pid  = fork();
	printf("fork returned:%d\n", (int)pid);
	if(pid < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if(pid == 0) {
		printf("I am the child with pid: %d\n", (int)pid);
		dosomework("Child");
		//sleep(5);
		printf("Child exiting\n");
		exit(42);
	} else {
		printf("I am the parent with pid: %d\n", (int)getpid());
		dosomework("Parent");
		int status = 0;
		pid_t childpid = wait(&status);	// waiting for child exiting
		printf("Parent knows child with pid:%d finished wth status:%d\n", childpid, status);
		int childReturnVal = WEXITSTATUS(status);
		printf("return values is:%d\n", childReturnVal);
	}
	
	return 0;
}
