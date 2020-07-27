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
		printf("No nodes available to print\n");
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

struct node *insert_position(struct node *locroot, int value, int pos)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->link = NULL;
	struct node *current = NULL, *traverse = locroot;
	while(pos-1) {
		if(traverse == NULL) {
			printf("position not available to insert\n");
			return locroot;
		}
		current = traverse;
		traverse = traverse->link;
		pos--;
	}
	temp->link = traverse;
	current->link = temp;
	return locroot;
}



int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 800);
	root = insert_begin(root, 500);
	root = insert_begin(root, 100);
	root = insert_end(root, 300);
	root = insert_end(root, 100);
	root = insert_end(root, 400);

	print_iteration(root);
	printf("\n");

	print_recursion(root);
	printf("\n");

	root = insert_position(root, 700, 5);

	print_iteration(root);
	printf("\n");

	return 0;
}
