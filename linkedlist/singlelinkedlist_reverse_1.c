#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *insert_begin(struct node *locroot, int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->link = NULL;
	if(locroot == NULL) {
		locroot = temp;
		return locroot;
	}
	else {
		temp->link = locroot;
		locroot = temp;
		return locroot;
	}
}

struct node *insert_end(struct node *locroot, int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->link = NULL;
	if(locroot == NULL) {
		locroot = temp;
		return locroot;
	}
	else {
		struct node *traverse = locroot;
		while(traverse->link != NULL) {
			traverse = traverse->link;
		}
		traverse->link = temp;
		return locroot;
	}
}

void print_iteration(struct node *locroot)
{
	if(locroot == NULL) {
		printf("no nodes available in list\n");
		return;
	}
	else {
		struct node *traverse = locroot;
		while(traverse != NULL) {
			printf("%d -> ", traverse->data);
			traverse = traverse->link;
		}
		return;
	}
}

void print_recursion(struct node *locroot)
{
	if(locroot == NULL) {
		return;
	}
	printf("%d -> ", locroot->data);
	print_recursion(locroot->link);
}

void print_reverse_recursion(struct node *locroot)
{
	if(locroot == NULL) {
		return;
	}
	print_reverse_recursion(locroot->link);
	printf("%d -> ", locroot->data);
}

struct node *reverse_iteration(struct node *locroot)
{
	struct node *current = locroot, *prev = NULL, *next = NULL;
	while(current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	return prev;
}

void bubble_sort(struct node *locroot)
{
	int temp;
	struct node *current = locroot;
	struct node *prev = NULL, *next = NULL;
	while(current != NULL) {
		prev = locroot;
		next = locroot->link;
		while(next != NULL) {
			if(prev->data > next->data) {
				temp = prev->data;
				prev->data = next->data;
				next->data = temp;
			}
			prev = prev->link;
			next = next->link;
		}
		current = current->link;
	}
}
		

int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 500);
	root = insert_begin(root, 100);
	root = insert_begin(root, 800);
	root = insert_end(root, 400);
	root = insert_end(root, 200);
	root = insert_end(root, 600);

	print_iteration(root);
	printf("\n");
	
	print_recursion(root);
	printf("\n");

	print_reverse_recursion(root);
	printf("\n");
	
	print_iteration(root);
	printf("\n");
	
	root = reverse_iteration(root);

	print_iteration(root);
	printf("\n");
	
	bubble_sort(root);

	print_iteration(root);
	printf("\n");


	return 0;
}
