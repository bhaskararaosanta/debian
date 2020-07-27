#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct sum_runner_str {
	long long limit;
	long long answer;
};

// Thread function to generate sum of 0 to N
void *sum_runner(void *arg)
{
	struct sum_runner_str *arg_struct = (struct sum_runner_str *)arg;

	long long sum = 0;
	long long i;
	for(i = 0; i < arg_struct->limit; i++) {
		sum += i;
	}
	arg_struct->answer = sum;
	
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	if(argc < 2) {
		printf("Usage:%s along with enter four long long integers.\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int i;
	int num_args = argc - 1;
	long long limit = atoll(argv[1]);

	/* pthread_t data type is defines in /include/bits/pthreadtypes.h using typedef specifier as follows:
	 *	typedef unsigned long int pthread_t;
	 * pthread_attr_t data type is indicated in /include/bits/pthreadtypes.h file as follows
	 * 	union pthread_attr_t {
	 *		char __size[__SIZEOF_PTHREAD_ATTR_T];
	 *		long int __align;
	 *	}; */
	
	struct sum_runner_str args[num_args];
	
	pthread_t tids[num_args];

	for(i = 0; i < num_args; i++) {
		args[i].limit = atoll(argv[i+1]);
		pthread_attr_t attr; 
		pthread_attr_init(&attr);
		/* int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); */
		pthread_create(&tids[i], &attr, sum_runner, &args[i]);
	}

	// Do other stuff here until thread finishes its work
	for(i = 0; i < num_args; i++) {
		// wait until thread is done
		pthread_join(tids[i], NULL);
		printf("sum of thread %ld = %lld\n", tids[i], args[i].answer);
	}


	return 0;
}

