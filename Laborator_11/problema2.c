#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct adjancent_matrix {
	int matrix;
	int cost;
} adjancent_matrix;

typedef struct edge_vector {
	int to;
	int from;
	int cost;
	int size;
} edge_vector;

typedef struct graph {
	int V;
	adjancent_matrix **matrix;
	edge_vector *vector;
} *Graph;

Graph init_graph (int V)
{
	Graph new;
	int i, j;

	new = malloc(sizeof(struct graph));
	new->matrix = malloc(V * sizeof(adjancent_matrix*));
	for (i = 0; i < V; i++)
		new->matrix[i] = malloc(V * sizeof(adjancent_matrix));
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			new->matrix[i][j].matrix = 0;
	new->V = V;
	return new;
}

Graph insert_edge (Graph graph_m, int from, int to, int cost)
{
	graph_m->matrix[from][to].matrix = 1;
	graph_m->matrix[to][from].matrix = 1;
	graph_m->matrix[from][to].cost = cost;
	graph_m->matrix[to][from].cost = cost;
	return graph_m;
}

Graph freeGraph (Graph graph_m)
{
	int i;

	for (i = 0; i < graph_m->V; i++)
		free(graph_m->matrix[i]);
	free(graph_m->matrix);
	free(graph_m);
	return NULL;
}

int inDegree(Graph graph_m, int to)
{
	int count, i;

	for (i = 0; i < graph_m->V; i++)
		if(graph_m->matrix[i][to].matrix == 1)
			count++;
	return count;
}

void print_graph(Graph graph_m)
{
	int i, j;

	printf("\n");
	for (i = 0; i < graph_m->V; i++) {
		for (j = i; j < graph_m->V; j++)
			if(graph_m->matrix[i][j].matrix == 1)
				printf("%d-->%d\n", i, j);
	}
}

edge_vector* compose_edge_vect(Graph graph_m)
{
	edge_vector *new;
	int i, j, k = 0;

	new = malloc(100 * sizeof(edge_vector));
	for (i = 0; i < graph_m->V; i++) {
		for (j = i; j < graph_m->V; j++)
			if(graph_m->matrix[i][j].matrix == 1){
				(*(new + k)).from = i;
				(*(new + k)).to = j;
				(*(new + k)).cost = graph_m->matrix[i][j].cost;
				k++;
			}
	}
	new->size = k;
	return new;
}

void printeaza_vector(edge_vector *vector, Graph graph_m)
{
	int i;

	for (i = 0; i < vector->size; i++) {
		printf("%d-->%d, cost: %d \n", 
			vector[i].from, vector[i].to, vector[i].cost);
	}
}

void swap(int *a, int *b)
{
	int aux;
	
	aux = *a;
	*a = *b;
	*b = aux;
}

int partition(edge_vector v[], int start, int end, Graph graph_m)
{
	int i;
	int pivot = start;
	int index = start;

	for (i = start + 1; i <= end; i++) {
		if (v[i].cost < v[pivot].cost) {
			index = index + 1;
			swap(&v[i].cost, &v[index].cost);
			swap(&v[i].to, &v[index].to);
			swap(&v[i].from, &v[index].from);
		}
	}
	swap(&v[start].cost, &v[index].cost);
	swap(&v[start].to, &v[index].to);
	swap(&v[start].from, &v[index].from);
	return index;
}

void quicksort(edge_vector *vector, int start, int end, Graph graph_m)
{
	int pivot;

	if(start < end) {
		pivot = partition(vector, start, end, graph_m);
		quicksort(vector, start, pivot - 1, graph_m);
		quicksort(vector, pivot + 1, end, graph_m);
	}
}

int Kruskal(Graph graph_m)
{
	int i, a, b, c, k, cost = 0;
	Graph graph_ama = init_graph(graph_m->V);
	int *colored = malloc(graph_m->V * sizeof(int));

	for (i = 0; i < graph_m->V; i++)
		colored[i] = i;
	for (i = 0; i < graph_m->vector->size; i++) {
		a = graph_m->vector[i].from;
		b = graph_m->vector[i].to;
		if (graph_m->matrix[a][b].matrix == 1)
			if(colored[a] != colored[b])
			{
				graph_ama = insert_edge(graph_ama,
					a, b, graph_m->vector[i].cost);
				cost = cost + graph_m->vector[i].cost;
				c = colored[b];
				for (k = 0; k < graph_m->V; k++)
					if(colored[k] == c)
						colored[k] = colored[a];
			}
	}
	print_graph(graph_ama);
	graph_ama = freeGraph(graph_ama);
	free(colored);
	return cost;
}

int main()
{
	Graph graph_m;

	// Initializare graf
	graph_m = init_graph(6);

	// Constituire graf
	graph_m = insert_edge(graph_m, 0, 1, 15);
	graph_m = insert_edge(graph_m, 1, 4, 10);
	graph_m = insert_edge(graph_m, 2, 4, 8);
	graph_m = insert_edge(graph_m, 0, 2, 11);
	graph_m = insert_edge(graph_m, 1, 5, 5);
	graph_m = insert_edge(graph_m, 4, 5, 20);
	graph_m = insert_edge(graph_m, 2, 5, 9);
	graph_m = insert_edge(graph_m, 3, 5, 2);
	graph_m = insert_edge(graph_m, 1, 3, 3);

	// printare muchii	
	edge_vector *vector = compose_edge_vect(graph_m);
	graph_m->vector = vector;
	printf("Muchiile sunt:\n");
	printeaza_vector(graph_m->vector, graph_m);

	printf("\n");
	quicksort(graph_m->vector, 0, graph_m->vector->size - 1, graph_m);
	printf("Muchiile sortate cu quicksort sunt:\n");
	printeaza_vector(graph_m->vector, graph_m);
	printf("Costul: %d\n", Kruskal(graph_m));

	// eliberare memorie
	graph_m = freeGraph(graph_m);
	free(vector);
}
