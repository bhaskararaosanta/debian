#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
//#include <stddef.h>

struct Node {
	int value;
	struct Node *link;
};

int get_node_val(const Node *node)
{
	return node->value;
}

void set_node_val(Node *node, int val)
{
	node->value = val;
}

static size_t node_size(void)
{
	return sizeof(struct Node);
}

static void *allocate_node(void)
{
	return malloc(node_size());
}

Node *create_node(int data)
{
	Node *new_node;
	if((new_node = allocate_node()) == NULL) {
		// gracefully_handle_failure();
	}

	new_node->value = data;
	new_node->link = NULL;
	return new_node;
}

Node *append_node(Node *root, Node *to_add)
{
	if(root == NULL) {
		return NULL;
	}
	Node *traverse = root;
	while(traverse->link) {
		traverse = traverse->link;
	}
	traverse->link = to_add;
	to_add->link = NULL;
	return root;
}

Node *prepend_node(Node *root, Node *to_add)
{
	to_add->link = root;
	root = to_add;
	return root;
}

Node *search_node(const Node *root, int search_val)
{
	for(const Node *traverse = root; traverse != NULL; traverse = traverse->link) {
		if(traverse->value == search_val) {
			return (Node *)traverse;
		}
	}
	return NULL;
}

Node *delete_node(Node *root, int delete_val)
{
	Node **indirect = &root;
	while((*indirect)->value != delete_val) {
		indirect = &(*indirect)->link;
	}
	*indirect = (*indirect)->link;
	return root;
}

void print_all(const Node *root)
{
	for(const Node *traverse = root; traverse != NULL; traverse = traverse->link) {
		printf("%d -> ", traverse->value);
	}
	puts("NULL");
}

void free_all(Node *root)
{
	for(Node *traverse = root; traverse != NULL; traverse = traverse->link) {
		free(root);
	}
}
