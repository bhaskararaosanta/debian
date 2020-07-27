#include <stdio.h>
#include "linkedlist.h"

int main()
{
	Node *root = create_node(12);
	append_node(root, create_node(20));
	root = prepend_node(root, create_node(30));
	print_all(root);
	printf("Head is:%d\n", get_node_val(root));
	set_node_val(root, 32);
	print_all(root);
	root = delete_node(root, 32);
	if(search_node(root, 20)) {
		printf("%d found in the list\n", 20);
	}
	print_all(root);
	//free_all(root);
	
	return 0;
}
