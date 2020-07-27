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
		printf("no nodes available to print\n");
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

struct node *reverse_iteration(struct node *locroot)
{
	struct node *current = locroot;
	struct node *prev = NULL, *next = NULL;
	while(current != NULL) {
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	return prev;
}



int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 300);
	root = insert_begin(root, 600);
	root = insert_begin(root, 900);
	root = insert_begin(root, 200);
	root = insert_end(root, 400);
	root = insert_end(root, 100);
	root = insert_end(root, 500);

	print_iteration(root);
	printf("\n");

	print_recursion(root);
	printf("\n");

	root = reverse_iteration(root);

	print_iteration(root);
	printf("\n");

	return 0;
}
