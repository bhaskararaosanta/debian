/* Linked list program using global head or root variable */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void InsertBegin(int);
void Print(void);

struct node *head;

int main()
{
	head = NULL;
	printf("How many nodes:\n");
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("Enter the node data:\n");
		scanf("%d", &x);
		InsertBegin(x);
		Print();
	}
	return 0;
}


void InsertBegin(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(head != NULL)
		temp->next = head;
	head = temp;
}

void Print(void)
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

