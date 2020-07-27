#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int cpid, pipefd[2];
	char wbuf[30] = "Embedded is great", rbuf[30];
	/* int pipe(int pipefd[2]); */
	pipe(pipefd);
	/* void fork(void); */
	if((cpid = fork()) < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(cpid == 0) {
		sleep(3);
		printf("I am in child process\n");
		close(pipefd[1]); // closing write end of pipe
		read(pipefd[0], rbuf, sizeof(rbuf));
		read(pipefd[0], rbuf, sizeof(rbuf));
		//close(pipefd[0]);
		printf("data read from parent using pipe:%s\n", rbuf);
	}
	else {
		printf("I am in parent process\n");
		close(pipefd[0]); // closing read end of pipe
		write(pipefd[1], wbuf, sizeof(wbuf));
		write(pipefd[1], wbuf, sizeof(wbuf));
		//close(pipefd[1]);
		printf("data written to child using pipe:%s\n", wbuf);
	}
	
	return 0;
}

