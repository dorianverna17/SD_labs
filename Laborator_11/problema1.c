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
	graph_m->matrix[from][to].cost = cost;
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

	for (i = 0; i < graph_m->V; i++) {
		printf("Muchiile care pleaca din nodul %d sunt:\n", i);
		for (j = 0; j < graph_m->V; j++)
			if(graph_m->matrix[i][j].matrix == 1)
				printf("%d-->%d\n", i, j);
		printf("\n");
	}
}

edge_vector* compose_edge_vect(Graph graph_m)
{
	edge_vector *new;
	int i, j, k = 0;

	new = malloc(100 * sizeof(edge_vector));
	for (i = 0; i < graph_m->V; i++) {
		for (j = 0; j < graph_m->V; j++)
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

int main()
{
	Graph graph_m;

	// Initializare graf
	graph_m = init_graph(16);

	// Constituire graf
	graph_m = insert_edge(graph_m, 1, 2, 1);
	graph_m = insert_edge(graph_m, 0, 2, 2);
	graph_m = insert_edge(graph_m, 0, 1, 3);
	graph_m = insert_edge(graph_m, 2, 10, 4);
	graph_m = insert_edge(graph_m, 1, 4, 5);
	graph_m = insert_edge(graph_m, 4, 5, 6);
	graph_m = insert_edge(graph_m, 4, 6, 7);
	graph_m = insert_edge(graph_m, 4, 3, 8);
	graph_m = insert_edge(graph_m, 3, 4, 9);
	graph_m = insert_edge(graph_m, 6, 13, 10);
	graph_m = insert_edge(graph_m, 13, 14, 11);
	graph_m = insert_edge(graph_m, 6, 14, 12);
	graph_m = insert_edge(graph_m, 6, 7, 13);
	graph_m = insert_edge(graph_m, 14, 15, 14);
	graph_m = insert_edge(graph_m, 7, 15, 15);
	graph_m = insert_edge(graph_m, 3, 8, 16);
	graph_m = insert_edge(graph_m, 8, 2, 17);
	graph_m = insert_edge(graph_m, 7, 8, 18);
	graph_m = insert_edge(graph_m, 1, 12, 19);
	graph_m = insert_edge(graph_m, 11, 12, 20);
	graph_m = insert_edge(graph_m, 11, 10, 21);
	graph_m = insert_edge(graph_m, 8, 9, 22);
	graph_m = insert_edge(graph_m, 9, 2, 23);

	edge_vector *vector = compose_edge_vect(graph_m);
	graph_m->vector = vector;
	printf("Muchiile sunt:\n");
	printeaza_vector(graph_m->vector, graph_m);

	// eliberare memorie
	graph_m = freeGraph(graph_m);
	free(vector);
}
