#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;

void *sum_runner(void *arg)
{
	long long *argptr = (long long *)arg;
	long long limit = *argptr;
	int i;
	for(i = 0; i < limit; i++) {
		sum += i;
	}
	pthread_exit(0);
}


int main(int argc, char *argv[])
{
	if(argc < 2) {
		printf("Usage :%s < num\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int retthread;
	long long limit = atoll(argv[1]);
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); */
	retthread = pthread_create(&tid, &attr, sum_runner, &limit);

	printf("return value of thread create:%d\n", retthread);

	pthread_join(tid, NULL);

	printf("Sum = %d\n", sum);

	return 0;
}
