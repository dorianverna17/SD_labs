#include <stdio.h>

#include "undirected_graph.h"
#include "helpers.h"

void graph_insert_edge(undirected_graph_t * const graph,
    const size_t source_id,
    const size_t destination_id) {
	if(source_id != destination_id) {
		if (graph->adj_matrix[source_id][destination_id] != true) {
			graph->adj_matrix[source_id][destination_id] = true;
			graph->adj_matrix[destination_id][source_id] = true;
		}
	}
}

void graph_remove_edge(undirected_graph_t * const graph,
    const size_t source_id,
    const size_t destination_id) {
	graph->adj_matrix[source_id][destination_id] = false;
	graph->adj_matrix[destination_id][source_id] = false;
}

bool graph_is_edge(undirected_graph_t * const graph,
    const size_t source_id,
    const size_t destination_id) {
	if (graph->adj_matrix[source_id][destination_id] == true)
		return true;
    return false;
}
