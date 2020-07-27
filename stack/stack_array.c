#include <stdio.h>
#define	MAX_SIZE	100

int A[MAX_SIZE];
int top = -1;

void push(int x)
{
	if(top == MAX_SIZE - 1) {
		printf("Error: stack overflow\n");
		return;
	}
	A[++top] = x;
}

void pop(void)
{
	if(top == -1) {
		printf("Error: no element to pop\n");
		return;
	}
	top--;
}

int top_element()
{
	return A[top];
}

void PRINT(void)
{
	int i;
	printf("stack: ");
	for(i = 0; i <= top; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	push(2);	PRINT();
	push(5);	PRINT();
	push(10);	PRINT();
	pop();		PRINT();
	push(12);	PRINT();
	top_element();


	return 0;
}
