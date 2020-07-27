#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int pipefd[2], cpid;
	char rbuf[30], wbuf[30] = "Embedded is great";
	/* int pipe(int pipefd[2]); */
	pipe(pipefd);
	/* void fork(void); */
	if((cpid = fork())< 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(cpid == 0) {
		printf("I am in child process\n");
		//sleep(3);
		close(pipefd[1]);	// closing write end of pipe
		read(pipefd[0], rbuf, sizeof(rbuf));
		printf("data read through pipe:%s\n", rbuf);
		close(pipefd[0]);
	}
	else {
		printf("I am in parent process\n");
		close(pipefd[0]);	// closing read end of pipe
		write(pipefd[1], wbuf, sizeof(wbuf));
		printf("data written to pipe:%s\n", wbuf);
		close(pipefd[1]);
	}

	return 0;
}

