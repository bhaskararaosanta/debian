#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum = 0;

// Thread function to generate sum of 0 to n
void *sum_runner(void *arg)
{
	long long *limit_ptr = (long long *)arg;
	long long limit = *limit_ptr;

	//long long sum = 0;
	long long i;
	for(i = 0; i <= limit; i++) {
		sum += i;
	}
	
	// what to do with the answer
	pthread_exit(0);
}


int main(int argc, char *argv[])
{
	if(argc < 2) {
		printf("Usage: %s <num>\n", argv[0]);
		exit(1);
	}

	long long limit = atoll(argv[1]);
	printf("size of long long : %d\n", sizeof(long long));

	// Thread creation
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, sum_runner, &limit);

	// wait unti thread is done its work
	pthread_join(tid, NULL);

	printf("Sum is : %lld\n", sum);
}
