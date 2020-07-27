#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define	NO_OF_LOOPS	5000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

long long sum = 0;

void *count_func(void *arg)
{
	//long long *limit_ptr = (long long *)arg;
	//long long limit = *limit_ptr;
	int offset = *(int *)arg;
	long long i;

	for(i = 0; i < NO_OF_LOOPS; i++) {
		/* critical section starts */
		pthread_mutex_lock(&mutex);
		sum += offset;
		pthread_mutex_unlock(&mutex);
		/* critical section ends */
	}
	pthread_exit(NULL);
}


int main()
{
	int offset1 = 1;
	int offset2 = -1;
	int ret1, ret2;

	pthread_t ida;
	pthread_attr_t ittra;
	pthread_attr_init(&ittra);
	ret1 = pthread_create(&ida, &ittra, count_func, &offset1);
	/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); */
	printf("return value of thread1 create:%d\n", ret1);

	pthread_t idb;
	pthread_attr_t ittrb;
	pthread_attr_init(&ittrb);
	ret2 = pthread_create(&idb, &ittrb, count_func, &offset2);
	/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); */
	printf("return value of thread2 create:%d\n", ret2);

	pthread_join(ida, NULL);
	pthread_join(idb, NULL);

	printf("Sum = %lld\n", sum);


	return 0;
}
