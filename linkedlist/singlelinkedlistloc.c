/* Linked list program using local head or root variable */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *InsertBegin(struct node *, int);
void Print(struct node *);

//struct node *head;

int main()
{
	struct node *head = NULL;
	printf("How many nodes:\n");
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Enter the node data:\n");
		scanf("%d", &x);
		head = InsertBegin(head, x);
		Print(head);
	}
	return 0;
}


struct node *InsertBegin(struct node *head, int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(head != NULL)
		temp->next = head;
	head = temp;
}

void Print(struct node *head)
{
	struct node *temp = head;
	printf("List is:");
	while(temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

