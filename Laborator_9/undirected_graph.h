#ifndef __UGRAPH_H__
#define __UGRAPH_H__

#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    size_t node_count;
    bool **adj_matrix;
} undirected_graph_t;

typedef double (*visit_func_t)(const size_t);

undirected_graph_t init_undirected_graph(const size_t);

undirected_graph_t *alloc_undirected_graph(const size_t);

void graph_write(undirected_graph_t * const graph, char *const path);
undirected_graph_t *graph_load(const char *path);

void graph_print(undirected_graph_t * const graph);

bool graph_valid_id(undirected_graph_t * const, const size_t);

void graph_insert_edge(undirected_graph_t * const,
    const size_t,
    const size_t);

void graph_remove_edge(undirected_graph_t * const,
    const size_t,
    const size_t);

bool graph_is_edge(undirected_graph_t * const,
    const size_t,
    const size_t);

#endif
