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
	struct node *traverse = locroot;
	if(locroot == NULL) {
		printf("No nodes available to print.\n");
		return;
	}
	else {
		while(traverse != NULL) {
			printf("%d -> ", traverse->data);
			traverse = traverse->link;
		}
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
		printf("position not available to insert\n");
		return locroot;
	}
	else {
		struct node *traverse = locroot, *next = locroot;
		next = next->link;
		while((traverse->link != NULL) && ((position-1) != 0)) {
			next = next->link;
			traverse = traverse->link;
			position--;
		}
		temp->link = next;
		traverse->link = temp;
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
		printf("No nodes available to delete at begin\n");
		return NULL;
	}
	else {
		struct node *temp = locroot;
		locroot = temp->link;
		temp->link = NULL;
		free(temp);
		return locroot;
	}
}

void delete_at_end(struct node *locroot)
{
	struct node *prev = NULL, *traverse = locroot;
	while(traverse->link != NULL) {
		prev = traverse;
		traverse = traverse->link;
	}
	prev->link = NULL;
	free(traverse);
}

int main()
{
	struct node *root = NULL;
	root = insert_begin(root, 500);
	root = insert_begin(root, 700);
	root = insert_begin(root, 300);
	root = insert_end(root, 900);
	root = insert_end(root, 200);
	root = insert_end(root, 100);

	print_iteration(root);
	printf("\n");

	print_recursion(root);
	printf("\n");

	/* insert_position(root_address, value_to_place, position_to_place); */
	root = insert_position(root, 400, 4);

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

	delete_at_end(root);

	print_iteration(root);
	printf("\n");

	return 0;
}
