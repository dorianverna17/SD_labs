#include <stdio.h>

#include "dequeue.h"
#include "undirected_graph.h"


void graph_traverse_DFS_recursive(undirected_graph_t * const graph,
    bool * const visited,
    const size_t start_node_id,
    visit_func_t func) {
	printf("%d\n", start_node_id);
	size_t i;
	visited[start_node_id] = true;
	func(start_node_id);
	for (i = 0; i < graph->node_count; i++) {
		if (graph_is_edge(graph, start_node_id, i))
			if (*(visited + i) == false) {
				graph_traverse_DFS_recursive(graph, visited, i, func);
			}
	}
}


void graph_traverse_DFS_iterative(undirected_graph_t * const graph,
    const size_t start_node_id,
    visit_func_t func) {
	int x, y;
	bool visited[100];
	printf("da\n");
	dequeue_t *stack;
	stack = alloc_deq();
	push_back(stack, start_node_id);
	while (size(stack) > 0)
	{
		x = back(stack);
		visited[x] = true;
		pop_back(stack);
		printf("%d\n", x);
		func(x);
		for(y = 0; y <= graph->node_count; y++) {
			if (graph_is_edge(graph, x, y) && x != y && visited[y] == false)
			{				
				visited[y] = true;
				push_back(stack, y);
			}
		}
	}
}


void graph_traverse_BFS(undirected_graph_t * const graph,
    const size_t start_node_id,
    visit_func_t func) {

	int x, y;
	bool visited[100];
	printf("da\n");
	dequeue_t *stack;
	stack = alloc_deq();
	push_back(stack, start_node_id);
	while (size(stack) > 0)
	{
		x = front(stack);
		visited[x] = true;
		pop_front(stack);
		printf("%d\n", x);
		func(x);
		for(y = 0; y <= graph->node_count; y++) {
			if (graph_is_edge(graph, x, y) && visited[y] == false)
			{				
				visited[y] = true;
				push_back(stack, y);
			}
		}
	}
}
