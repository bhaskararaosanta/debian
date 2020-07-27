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
		printf("No nodes available to display\n");
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

struct node *insert_position(struct node *locroot, int value, int position)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->link = NULL;
	if(locroot == NULL) {
		printf("no position available to isnert node\n");
		return locroot;
	}
	else {
		struct node *current = locroot, *next = locroot;
		next = next->link;
		while(((current->link) != NULL) && ((position-1) != 0)) {
			current = current->link;
			next = next->link;
			position--;
		}
		temp->link = next;
		current->link = temp;
		return locroot;
	}
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
	struct node *traverse = locroot;
	struct node *prev = NULL, *next = NULL;
	while(traverse->link != NULL) {
		prev = locroot;
		next = prev->link;
		while(next != NULL) {
			int temp;
			if(prev->data >= next->data) {
				temp = prev->data;
				prev->data = next->data;
				next->data = temp;
			}
			prev = prev->link;
			next = next->link;
		}
		traverse = traverse->link;
	}
}


struct node *delete_at_begin(struct node *locroot)
{
	if(locroot == NULL) {
		printf("No nodes available to perform task\n");
		return locroot;
	}
	else {
		struct node *temp = locroot;
		locroot = temp->link;
		temp->link = NULL;
		free(temp);
		return locroot;
	}
}

struct node *delete_at_end(struct node *locroot)
{
	if(locroot == NULL) {
		printf(" No nodes available to delete\n");
		return locroot;
	}
	else {
		struct node *current = locroot, *prev = locroot;
		while(current->link != NULL) {
			prev = current;
			current = current->link;
		}
		prev->link = NULL;
		free(current);
		return locroot;
	}
}

int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 400);
	root = insert_begin(root, 800);
	root = insert_begin(root, 900);
	root = insert_end(root, 500);
	root = insert_end(root, 100);
	root = insert_end(root, 300);

	print_iteration(root);
	printf("\n");

	print_recursion(root);
	printf("\n");

	/* insert_position(root, int data, int position); */
	root = insert_position(root, 200, 4);
	print_iteration(root);
	printf("\n");

	root = reverse_iteration(root);
	print_iteration(root);
	printf("\n");

	bubble_sort(root);
	print_iteration(root);
	printf("\n");

	root = delete_at_begin(root);
	print_iteration(root);
	printf("\n");

	root = delete_at_end(root);
	print_iteration(root);
	printf("\n");



	return 0;
}
