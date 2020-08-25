#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	double data;
	struct node *next;
}node_t;

typedef double (*node_func_t)(const node_t *node);

// double functie(double x)
// {
// 	return 2 * x;
// }

// void map(node_t *x , node_func_t func)
// {
// 	node_t *it = x;
// 	while(it->next)
// 	{
// 		printf("%lf ", func(it->data));
// 		it = it->next;
// 	}
// }
double functie(const node_t *x)
{
	return (2 * x->data);
}
void map(node_t *x , node_func_t func)
{
	node_t *it = x;
	while(it)
 	{
 		printf("%lf ", func(it));
 		it = it->next;
 	}
}

void filter(node_t ** x, node_func_t func)
{
	node_t *it = *x;
	while(func(it) == 1)
	{
		if(it->next == NULL)
			{
			*x = NULL;
			break;
			}
		*x = (*x)->next;
		it = *x;
	}
	while(it && (it)->next)
 	{
 		if(func((it)->next) == 1)
 			{
			(it)->next = (it)->next->next;
 			}
 		else
 			if(it->next != NULL)	
 				it = ((it)->next);
 	}
}

double aggregate( node_t *x, node_func_t func)
{
	double S = 0;
	node_t *it = x;
	while(it)
 	{
 		it->data = func(it);
 			S = S + it->data;
 		it = it->next;
 	}
 	return S;
}

void push_front(node_t **x, double data)
{
	node_t *new_node = malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = *x;
	*x = new_node;
}

void afisare(node_t *x)
{
	node_t *it = x; 
	while (it != NULL) 
	{
		printf("%lf ", it->data);
		it = it->next;
	}
}

int main()
{
	node_t *lst;
	lst = NULL;
	double value;
	scanf("%lf", &value);
	push_front(&lst, value);
	scanf("%lf", &value);
	push_front(&lst, value);
	scanf("%lf", &value);
	push_front(&lst, value);
	scanf("%lf", &value);
	push_front(&lst, value);
	afisare(lst);
	//map(lst, functie);
	filter(&lst, functie);
	printf("\n");
	afisare(lst);
	//printf("%lf\n", aggregate(lst, functie));
	return 0;
}