#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum = 0;

// Thread function to generate sum of 0 to N
void *sum_runner(void *arg)
{
	long long *limit_ptr = (long long *)arg;
	long long limit = *limit_ptr;

	long long i;
	for(i = 0; i < limit; i++) {
		sum += i;
	}

	// sum is a global variable and all threads can use of it
	
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	if(argc < 2) {
		printf("Usage:%s along with enter long long integer.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	long long limit = atoll(argv[1]);

	/* pthread_t data type is defines in /include/bits/pthreadtypes.h using typedef specifier as follows:
	 *	typedef unsigned long int pthread_t;
	 * pthread_attr_t data type is indicated in /include/bits/pthreadtypes.h file as follows
	 * 	union pthread_attr_t {
	 *		char __size[__SIZEOF_PTHREAD_ATTR_T];
	 *		long int __align;
	 *	}; */
	
	pthread_t tid;
	pthread_attr_t attr; 
	pthread_attr_init(&attr);

	/* int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); */
	pthread_create(&tid, &attr, sum_runner, &limit);

	// Do other stuff here until thread finishes its work

	// wait until thread is done
	pthread_join(tid, NULL);

	printf("sum = %lld\n", sum);

	return 0;
}

