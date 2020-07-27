#include <stdio.h>
#include <stdlib.h>

struct bstnode {
	int data;
	struct bstnode *left;
	struct bstnode *right;
};

struct bstnode *getnewnode(int value)
{
	struct bstnode *newnode = (struct bstnode *)malloc(sizeof(struct bstnode));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}

/*void insert(struct bstnode **locroot,int value)
{
	if(*locroot == NULL) {
		*locroot = getnewnode(value);
		return *locroot;
	}
} */

struct bstnode *insert(struct bstnode *locroot, int value)
{
	if(locroot == NULL) {
		locroot = getnewnode(value);

	}
	else if(value <= locroot->data) {
		locroot->left = insert(locroot->left, value);
	}
	else {
		locroot->right = insert(locroot->right, value);
	}
	return locroot;
}

int main()
{
	struct bstnode *root = NULL;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	/*
	root = insert(&root, 12);
	root = insert(&root, 10);
	root = insert(&root, 20);
	*/

	return 0;
}
