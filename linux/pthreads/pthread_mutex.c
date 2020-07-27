#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define	NUM_LOOPS	5000000
long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *count_function(void *arg)
{
	int offset = *(int *)arg;
	int i;
	for(i = 0; i < NUM_LOOPS; i++) {
		// start of critical section
		pthread_mutex_lock(&mutex);
		sum += offset;
		pthread_mutex_unlock(&mutex);
		// end of critical section
	}
	pthread_exit(NULL);
}

int main()
{
	int offset1 = 1;
	int offset2 = -1;
	pthread_t id1;
	pthread_attr_t attr1;
	pthread_attr_init(&attr1);
	pthread_create(&id1, &attr1, count_function, &offset1);

	pthread_t id2;
	pthread_attr_t attr2;
	pthread_attr_init(&attr2);
	pthread_create(&id2, &attr2, count_function, &offset2);


	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	printf("sum = %lld\n", sum);

	return 0;
}


