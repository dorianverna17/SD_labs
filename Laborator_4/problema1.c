#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	double data;
	struct node *prev;
	struct node *next;
} node_t;

typedef double(*node_func_t)(node_t const * node);

double functie(const node_t *x)
{
	return (2 * x->data);
}
size_t remove_equal_sequence(node_t **begin, node_func_t func)
{
	int i;
	double x;
	node_t *it = *begin;
	node_t *aux;	
	while(it->next != NULL)
	{
		printf("da\n");
		x = func(it);
		while(func(it) == x && it != NULL)
		{
			printf("nu\n");
			it = it->next;
		}
		if(i >= 3)
			while(i > 0 && it != NULL)
			{
				printf("yes\n");
				aux = it->prev;
				remove(it);
				it = aux;
				i--;
			}
		it = it->next;
	}
}
void apply(node_t *begin, node_t *end, node_func_t func)
{
	node_t *it = begin;
	do{
		it->data = func(it);
		it = it->next;
	} while(it != end);
}
void push_after(node_t *current, node_t *new_node)
{
	new_node = malloc(sizeof(node_t));
	//scanf("%lf", &(new_node->data));
	new_node->data = 3;
	new_node->next = current->next;
	new_node->prev = current;
	current->next->prev = new_node;
	current->next = new_node; 
}
void push_front(node_t **head, node_t *new_node)
{
	// new_node = malloc(sizeof(node_t));
	//scanf("%lf", &(new_node->data));
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
void push_back(node_t **head, node_t *new_node)
{
	// new_node = malloc(sizeof(node_t));
	// scanf("%lf", &(new_node->data));
	node_t *it = *head;
	while(it->next)
	{
		it = it->next;
	}
	it->next = new_node;
	new_node->next = NULL;
	new_node->prev = it;
}
void remove_node(node_t **node)
{
	(*node)->prev->next = (*node)->next;
	(*node)->next->prev = (*node)->prev;
	free(*node);
}
node_t *nth_element(const node_t *head, const size_t nth)
{
	node_t *it = head;
	int i = 1;
	while (it != NULL) 
	{
		if(it->next == NULL)
			return it;
		if(i == nth)
		{
			return it;
		}
		it = it->next;
			i++;
	}
}
void afisare(node_t *x)
{
	node_t *it = x; 
	while (it != NULL) 
	{
		printf("%0.2lf ", it->data);
		it = it->next;
	}
}

void remove_items(List *head) {
	int i = 1;
	
	node *it = *head;
	node *aux;
	if (!(*head))
		return;
	if ((*head)->next == NULL && (*head)->prev == NULL) {
		return;
	} else {
		while (it) {
			if (i % 2 == 0 && it->value % 2 != 0) {
				if (it->prev == NULL && it->next != NULL) {
					aux = it;
					it->prev = NULL;
					it->next->prev = NULL;
					it = head->next;
					free(aux);
				} else if (it->prev != NULL && it->next == NULL){
					aux = it;
					it->prev->next = NULL;
					free(aux);
				} else {
					aux = it;
					it->prev->next = it->next;
					it->next->prev = it->prev;
					free(aux);
				}
			}
			it = it->next;
			i++;
		}
	}
}

int main()
{
	//problema 1
	node_t *lst;
	lst = NULL;
	int n, i;
	node_t *x;
	n = 2;
	for(i = 1; i <= n; i++)
	{
		x = malloc(sizeof(node_t));
		push_front(&lst, x);
	}
	n = 3;
	for(i = 1; i <= n; i++)
	{
		x = malloc(sizeof(node_t));
		x->data = i;
		push_back(&lst, x);
	}

	node_t *it = lst;
	i = 0;
	while (it != NULL) 
	{
		it = it->next;
		i++;
		if(i == 1)
			break;
	}
	push_after(it, x);
	afisare(lst);
	i = 0;
	while (it != NULL) 
	{
		it = it->next;
		i++;
		if(i == 1)
			break;
	}

	//problema 2
	remove_node(&it);
	printf("\n");
	afisare(lst);
	node_t *b;
	b = malloc(sizeof(node_t));
	b = nth_element(lst, 6);
	printf("%0.2lf\n", b->data);

	//problema 3
	node_t *c = lst;
	node_t *d = lst;
	while (it != NULL) 
	{
		it = it->next;
		i++;
		if(i == 1)
			c = it;
		if(i == 4)
			d = it;
	}
	apply(c, d, functie);
	afisare(lst);

	//problema 4
	c = lst;
	d = lst;
	printf("\n");
		while (it != NULL) 
	{
		it = it->next;
		i++;
		if(i == 1)
			c = it;
		if(i == 5)
			d = it;
	}
	remove_equal_sequence(&c, functie);
	afisare(lst);
	return 0;
}

