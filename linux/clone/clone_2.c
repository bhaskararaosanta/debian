#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sched.h>

#define	_GNU_SOURCE
#define	SIZESTACK	(1024 * 1024)

int child_proc(void *arg)
{
	printf("Child rocess arg = %s\n", (char *)arg);
	sleep(2);
	return 0;
}

int main()
{
	char *stack, *stackhead;
	char *str = "Hello world";
	pid_t pid;
	int status;

	stack = (char *)malloc(SIZESTACK);
	if(!stack) {
		fprintf(stderr, "unable to allocate stack\n");
		exit(1);
	}

	stackhead = stack + SIZESTACK - 1;
	printf("parent pid = %d\n", getpid());

	/* int clone(int (*fn)(void *). void *child_stack, int flags, void *arg, ...); */
	pid = clone(child_proc, stackhead, SIGCHLD, str);
	if(pid == -1) {
		fprintf(stderr, "unable to clone\n");
		free(stack);
		exit(1);
	}
	printf("child pid = %d\n", pid);
	waitpid(pid, &status, 0);

	printf("Done\n");

	return 0;
}
			
