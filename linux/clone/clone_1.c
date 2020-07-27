#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define	_GNU_SOURCE
#define	SIZESTACK	(1024 * 1024)

int child_proc(void *arg)
{
	printf("Child process arg = %s\n", (char *)arg);
	sleep(2);
	return 0;
}
	
int main()
{
	char *stack, *stackhead;
	char *str = "Hello World";

	pid_t pid;
	int status;

	stack = (char *)malloc(SIZESTACK);
	if(!stack) {
		fprintf(stderr, "Unable to allocate stack\n");
		exit(1);
	}

	stackhead = stack + SIZESTACK - 1;
	printf("Parent pid = %d\n", getpid());

	/* int clone(int (*fn)(void *), void *child_stack,
	  		int flags, void *arg, ...); */

	pid = clone(child_proc, stackhead, SIGCHLD, str);
	if(pid == -1) {
		fprintf(stderr, "Unable to clone\n");
		free(stack);
		exit(1);
	}

	printf("Child pid = %d\n", pid);
	waitpid(pid, &status, 0);

	printf("Done\n");

	return 0;
}
