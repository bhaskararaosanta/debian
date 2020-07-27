#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum = 0;

void *sum_runner(void *arg)
{
	long long *argptr = (long long *)arg;
	long long limit = *argptr;
	long long i;

	for(i = 0; i < limit; i++) {
		sum += i;
	}
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	if(argc < 2) {
		printf("Usage :%s < include number to calculate along executable.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	long long limit = atoll(argv[1]);

	int retthread1, retthread2, i;
	pthread_t tid1;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	// thread creation:
	/* int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*thread_name)(void *), void *arg); */
	retthread1 = pthread_create(&tid1, &attr, sum_runner, &limit);
	printf("return value of thread creation:%d\n", retthread1);

	pthread_t tid2;
	//pthread_attr_t attr2;
	//pthread_attr_init(&attr2);

	// thread creation:
	/* int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*thread_name)(void *), void *arg); */
	retthread2 = pthread_create(&tid1, &attr, sum_runner, &limit);
	printf("return value of thread creation:%d\n", retthread2);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("Sum = %lld\n", sum);

	return 0;
}
