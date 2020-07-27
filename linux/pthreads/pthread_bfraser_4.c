#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define	NO_OF_LOOPS	200000
long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *sum_runner(void *arg)
{
	int *offset = (int *)arg;
	*offset = *(int *)arg;
	long long i = 0;
	for(i = 0; i < NO_OF_LOOPS; i++) {
		/* critical section starts */
		pthread_mutex_lock(&mutex);
		sum += *offset;
		pthread_mutex_unlock(&mutex);
		/* critical section ends */
	}
	pthread_exit(NULL);
}

int main()
{
	int thread1, thread2;
	int offset1 = +1;
	int offset2 = -1;

	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr1;
	pthread_attr_t attr2;

	pthread_attr_init(&attr1);
	/* int pthread_create(pthread_t *tid, pthread_attr_t *attr,\
	 * void *(*start_routine)(void *), void *arg); */
	if((thread1 = pthread_create(&tid1, &attr1, sum_runner, &offset1)) < 0) {
		printf("thread creation failed.\n");
		exit(EXIT_FAILURE);
	}
	printf("return value of pthread_create:%d\n", thread1);

	pthread_attr_init(&attr2);
	/* int pthread_create(pthread_t *tid, pthread_attr_t *attr, \
	 * void *(*start_routine)(void *), void *arg); */
	if((thread2 = pthread_create(&tid2, &attr2, sum_runner, &offset2)) < 0) {
		printf("thread2 creation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("return value of pthread_create:%d\n", thread2);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("sum = %lld\n", sum);

	return 0;
}

