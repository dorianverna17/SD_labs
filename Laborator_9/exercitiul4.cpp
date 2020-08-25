#include "helpers.h"
#include "undirected_graph.h"

void graph_traverse_DFS_recursive(undirected_graph_t * const graph,
    bool * const visited,
    const size_t start_node_id) {
	//printf("%d\n", start_node_id);
	size_t i;
	visited[start_node_id] = true;
	//func(start_node_id);
	for (i = 0; i < graph->node_count; i++) {
		if (graph_is_edge(graph, start_node_id, i))
			if (*(visited + i) == false) {
				graph_traverse_DFS_recursive(graph, visited, i);
			}
	}
}

size_t connected_componenets(undirected_graph_t *graph) {
	bool *visited = (bool *)malloc(graph->node_count * sizeof(bool));
    int i = 0;
    for(i = 0; i < graph->node_count; i++) {
       visited[i] = false;
    }
    int vecin;
    size_t nr = 0;
    for(vecin = 0; vecin < graph->node_count; vecin++) {
        if(visited[vecin] == false) {
            graph_traverse_DFS_recursive(graph, visited, vecin);
            nr++;
        }
    }
    return nr;
}
