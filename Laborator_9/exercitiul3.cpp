#include "helpers.h"
#include "dequeue.h"
#include "undirected_graph.h"

int *shortest_path(undirected_graph_t * const graph,
    const size_t source_id,
    const size_t destination_id) {

	// int x, y, nr = 0;
	// bool visited[100];
	// printf("da\n");
	// dequeue_t *stack;
	// stack = alloc_deq();
	// push_back(stack, source_id);
	// while (size(stack) > 0)
	// {
	// 	x = front(stack);
	// 	visited[x] = true;
	// 	pop_front(stack);
	// 	printf("%d\n", x);
	// 	for(y = 0; y <= graph->node_count; y++) {
	// 		if (graph_is_edge(graph, x, y) && visited[y] == false)
	// 		{
	// 			nr++;
	// 			if (y == destination_id)
	// 			{
	// 				printf("%d\n", nr);
	// 			}
	// 			visited[y] = true;
	// 			push_back(stack, y);
	// 		}
	// 	}
	// }
    return NULL;
}
