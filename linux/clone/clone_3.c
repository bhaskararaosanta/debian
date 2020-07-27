#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/wait.h>

#define	_GNU_SOURCE
#define	STACKSIZE	(1024 * 1824)

int child_proc(void *arg)
{
	printf("I am in child process with pid:%d\n", getpid());
	printf("argument received from parent process:%s\n", (char *)arg);
	sleep(2);
	return 0;
}

int main()
{
	int status;
	pid_t pid;
	char *stackhead, *stack, *str = "Hello";
	stack = (char *)malloc(STACKSIZE);
	if(!stack) {
		fprintf(stderr, "unable to allocate stack\n");
		exit(1);
	}

	stackhead = stack + STACKSIZE - 1;
	/* int clone(int (*fn)(void *), void *child_stack, int flags, void *arg, ...); */
	pid = clone(child_proc, stackhead, SIGCHLD, str);
	if(pid < 0) {
		perror("clone");
		exit(EXIT_FAILURE);
	}
	printf("return value of clone in parent process:%d\n", pid);
	printf("process id:%d\n", getpid());
	waitpid(pid, &status, 0);

	printf("Done\n");

	return 0;
}

