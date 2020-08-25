#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node_t;

void push_front(node_t **x, double data)
{
	node_t *new_node = malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = *x;
	*x = new_node;
}
void push_back(node_t **x, double data)
{
	if(!(*x))
	{
		*x = malloc(sizeof(node_t));
		(*x)->data = data;
	}
	node_t *new_node = malloc(sizeof(node_t));
	node_t *it = *x;
	while(it->next)
	{
		it = it->next;
	}

	it->next = new_node;
	new_node->data = data;
	new_node->next = NULL;
}
void afisare(node_t *x)
{
	node_t *it = x; 
	while (it != NULL) 
	{
		printf("%d\n", it->data);
		it = it->next;
	}
}
int main()
{
	node_t *lst;
	lst = NULL;
	int value;
	scanf("%d", &value);
	push_front(&lst, value);
	scanf("%d", &value);
	push_front(&lst, value);
	afisare(lst);
	scanf("%d", &value);
	push_back(&lst, value);
	scanf("%d", &value);
	push_back(&lst, value);
	afisare(lst);
	return 0;
}