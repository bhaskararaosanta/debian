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
		return temp;
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
		return temp;
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



int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 400);
	root = insert_begin(root, 700);
	root = insert_begin(root, 500);
	root = insert_end(root, 300);
	root = insert_end(root, 900);
	root = insert_end(root, 800);

	print_iteration(root);
	printf("\n");



	return 0;
}
