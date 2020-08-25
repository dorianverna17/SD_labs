/*
*	Created by Nan Mihai on 04.04.2020
*	Copyright (c) 2020 Nan Mihai. All rights reserved.
*	Laborator - Proiectarea algoritmilor (Grafuri)
*	Facultatea de Automatica si Calculatoare
*	Anul Universitar 2019-2020, Seria CD
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"
#include "stack.h"

void dfs(Graph graph, int *visited, int start_node, Stack *stack) {
	int i;
	visited[start_node] = 1;
	for (i = 0; i < graph->V; i++) {
		if (isArc(graph, start_node, i))
			if (*(visited + i) == 0) {
				dfs(graph, visited, i, stack);
			}
	}
	*stack = push(*stack, start_node);
}

void Top_sort(Graph g) {
	int i;
	Stack stack = initStack(0);
	stack = pop(stack);
	for (i = 0; i < g->V; i++) {
		g->visited[i] = 0;
	}
	for (i = 0; i < g->V; i++) {
		if (g->visited[i] == 0)
			dfs(g, g->visited, i, &stack);
	}
	int u;
	while(!isEmptyStack(stack)) {
		u = top(stack);
		stack = pop(stack);
		printf("%d\n", u);
	}
}

int floyd(Graph g) {
	int n = g->V, k, i, j;
	int d[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			d[i][j] = getCost(g, i, j);
		}
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++)
			for(j = 0; j < n; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
	}
	for (i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
}

void Dijkstra(Graph g, int sursa, int destinatie) {
	int p[100];
	int M = g->V;
	int d[g->V][g->V], s[100];
	int dmin, jmin = -1, i, j;
	for (i = 0; i < 100; i++) {
		p[i] = -1;
		s[i] = 0;
	}
	for (i = 0; i < g->V; i++) {
		p[i] = sursa;
		d[sursa][i] = getCost(g, sursa, i);
	}
	s[sursa] = 1;
	for (i = 0; i < g->V; i++) {
		dmin = INFINITY;
		for (j = 0; j < g->V; j++) {
			if(s[j] == 0 && dmin > d[sursa][j]) {
				dmin = d[sursa][j];
				jmin = j;
			}
		}
		if(jmin != -1) {
			s[jmin] = 1;
			for (j = 0; j < g->V; j++) {
				if (d[sursa][j] > d[sursa][jmin] + getCost(g, jmin, j)) {
					d[sursa][j] = d[sursa][jmin] + getCost(g, jmin, j);
					p[j] = jmin;
				}
			}
		}
	}
	j = destinatie;
	int vector_aux[100], k = 0, ok = 0;
	for (i = 0; i < 100; i++)
		vector_aux[i] = -1;
	while(j != sursa) {
		vector_aux[k] = j;
		k++;
		j = p[j];
	}
	if (d[sursa][destinatie] == INFINITY)
	{
		printf("Nu exista drum\n");
		return;
	}
	printf("%d ", sursa);
	for(i = k - 1; i >= 0 ; i--)
		printf("%d ", vector_aux[i]);
	printf("\n");
}

int main() {
	freopen("test2.in", "r", stdin);
	int V, type, i, x, y, z, M;
	scanf("%d %d", &V, &type);
	Graph graph = initGraph(V, type);
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		graph = insertEdge(graph, x, y, z);
	}
	printGraph(graph);
	drawGraph(graph, "graph1.dot");
	printf("Problema1:\n");
	Top_sort(graph);
	printf("Problema2:\n");
	floyd(graph);
	printf("Problema3:\n");
	Dijkstra(graph, 1, 5);
	graph = freeGraph(graph);
	return 0;
}