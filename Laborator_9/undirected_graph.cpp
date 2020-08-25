#include <stdio.h>

#include "undirected_graph.h"

undirected_graph_t init_undirected_graph(const size_t node_count) {
    undirected_graph_t graph = {
        .node_count = node_count,
        .adj_matrix = (bool **)malloc(node_count * sizeof(bool *))
    };

    for (size_t i = 0; i < node_count; i++) {
        graph.adj_matrix[i] = (bool *)calloc(node_count, sizeof(bool));
    }

    return graph;
}

undirected_graph_t *alloc_undirected_graph(const size_t node_count) {
    undirected_graph_t *graph = (undirected_graph_t *)malloc(sizeof(*graph));
    *graph = init_undirected_graph(node_count);
    return graph;
}

void graph_print(undirected_graph_t * const graph) {
    printf("%zd\n", graph->node_count);
    for (size_t i = 0; i < graph->node_count; i++) {
        for (size_t j = 0; j < graph->node_count; j++) {
            printf("%2d|", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void graph_write(undirected_graph_t * const graph, char *const path) {
    FILE *fd = fopen(path, "w");

    fprintf(fd, "%zd,from,to\n", graph->node_count);
    size_t edge_count = 0;
    for (size_t from_id = 0; from_id < graph->node_count; from_id++) {
        for (size_t to_id = from_id + 1; to_id < graph->node_count; to_id++) {
            if (graph->adj_matrix[from_id][to_id]
                || graph->adj_matrix[to_id][from_id]) {

                fprintf(fd, "%zd,%zd,%zd\n",edge_count, from_id, to_id);
                ++edge_count;
            }
        }
    }
    fclose(fd);
}

undirected_graph_t *graph_load(const char *path) {

    FILE *fd = fopen(path, "r");
    if (!fd)
        return NULL;

    size_t node_count = 0;
    size_t id, from, to;

    fscanf(fd, "%zd,from,to\n", &node_count);
    undirected_graph_t *graph = alloc_undirected_graph(node_count);


    while(fscanf(fd, "%zd,%zd,%zd\n", &id, &from, &to) != EOF) {
        //printf("%zd, from:%zd to: %zd\n", id, from, to);
        graph->adj_matrix[from][to] = true;
        graph->adj_matrix[to][from] = true;
    }
    fclose(fd);

    return graph;
}


bool graph_valid_id(undirected_graph_t * const graph,
    const size_t node_id) {
    bool is_valid = true;

    if (!graph)
        is_valid = false;
    else if (node_id >= graph->node_count)
        is_valid = false;

    return is_valid;
}
