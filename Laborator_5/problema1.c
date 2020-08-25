#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_SUCCESS 0
#define ERROR_DEQUEUE_EMPTY -1
#define ERROR_DEQUEUE_INTERNAL -2

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
} node_t;

typedef struct {
	node_t *front;
	node_t *back;
	size_t size;
} dequeue_t;

void init_lst(node_t **lst)
{
	*lst = NULL;
}

int front(dequeue_t *deq, double *value)
{
	if(deq->front == NULL)
		return ERROR_DEQUEUE_EMPTY;
	else
	{
		*value = deq->front->data;
		return *value;	
	}
}
int back(dequeue_t *deq, double *value)
{
	if(deq->back == NULL)
		return ERROR_DEQUEUE_EMPTY;
	else
	{
		*value = deq->back->data;
		return *value;
	}
}
int push_front(dequeue_t *deq, double value)
{
	node_t *new_node;
	new_node = malloc(sizeof(node_t));
	new_node->data = value;
	new_node->next = malloc(sizeof(node_t));
	new_node->prev = malloc(sizeof(node_t));
	if(deq == NULL)
	{
		deq->front = new_node;
		deq->back = new_node;
	}
	else
	{
		new_node->next = deq->front;
		deq->front = new_node;
	}
	deq->size++;
}
int push_back(dequeue_t *deq, double value)
{
	node_t *new_node;
	new_node = malloc(sizeof(node_t));
	new_node->data = value;
	new_node->next = malloc(sizeof(node_t));
	new_node->prev = malloc(sizeof(node_t));
	if(deq == NULL)
	{
		deq->front = new_node;
		deq->back = new_node;
	}
	else
	{
		new_node->prev = deq->back;
		deq->back = new_node;
	}
	deq->size++;
}
void pop_front(dequeue_t *deq)
{
	if(deq == NULL)
		return;
	else
	{
		node_t *aux = deq->front;
		deq->front = aux->next;
		aux = NULL;
		free(aux);
		deq->size--;
	}
}
void pop_back(dequeue_t *deq)
{
	if(deq == NULL)
		return;
	else
	{
		node_t *aux = deq->back;
		deq->back = aux->prev;
		aux = NULL;
		free(aux);
		deq->size--;
	}
}
size_t size(dequeue_t *deq);

int main()
{
	node_t *lst;
	init_lst(&lst);
	dequeue_t *deq;
	deq = malloc(sizeof(dequeue_t));
	deq->front = malloc(sizeof(node_t));
	deq->back = malloc(sizeof(node_t));
	deq->size = 0;
	push_front(deq, 2);
	push_front(deq, 4);
	push_back(deq, 2);
	push_back(deq, 3);
	pop_back(deq);
	pop_front(deq);
	return 0;
}