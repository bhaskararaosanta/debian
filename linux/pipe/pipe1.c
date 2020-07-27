#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int pipefd[2], cpid;
	char wbuf[30] = "Embedded is good", rbuf[30];
	/* int pipe(int pipefd[2]); */
	pipe(pipefd);
	/* pid_t fork(void); */
	if((cpid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(cpid == 0) {
		printf("I am in child process\n");
		close(pipefd[1]);	// closing write end of pipe
		read(pipefd[0], rbuf, sizeof(rbuf));
		printf("data read through pipe:%s\n", rbuf);
	}
	else {
		printf("I am in parent process\n");
		close(pipefd[0]);	// closing read end of pipe
		write(pipefd[1], wbuf, sizeof(wbuf));
		printf("data sent through pipe:%s\n", wbuf);
	}

	return 0;
}

