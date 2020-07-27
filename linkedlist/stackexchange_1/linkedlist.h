#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

/* Incomplete type used for "opaque pointer" */
struct Node;

typedef struct Node Node;
int get_node_val(const Node *node);
void set_node_val(Node *node, int val);
Node *create_node(int data);
Node *append_node(Node *root, Node *to_add);
Node *prepend_node(Node *root, Node *to_add);
Node *search_node(const Node *root, int search_val);
Node *delete_node(Node *root, int delete_val);
void print_all(const Node *root);
void free_all(Node *root);

#endif
