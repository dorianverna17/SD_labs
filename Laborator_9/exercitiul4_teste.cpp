#include <stdlib.h>

#include "helpers.h"
#include "undirected_graph.h"

#define GRAPH_BIG_PATH "graph_big.csv"
#define GRAPH_HUGE_PATH "graph_huge.csv"

undirected_graph_t *prepare_graph(void);
size_t connected_componenets(undirected_graph_t *graph);

float test_exercise4() {
    const size_t test_count = 6;
    const float points = 3.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0);

    undirected_graph_t *graph = prepare_graph();
    results[0] = connected_componenets(graph) == 1;

    graph_remove_edge(graph, 9, 8);
    results[1] = connected_componenets(graph) == 2;

    graph = alloc_undirected_graph(29);
    results[2] = results[0] > 0 && connected_componenets(graph) == 29;

    graph->adj_matrix[2][18] = graph->adj_matrix[18][2] = true;
    results[3] = connected_componenets(graph) == 28;

    graph = graph_load(GRAPH_BIG_PATH);
    results[4] = connected_componenets(graph) == 59;

    graph = graph_load(GRAPH_HUGE_PATH);
    results[5] = connected_componenets(graph) == 160;

    show_results(4.0, "connected components", expected, results);
    double total = 0;
    for (size_t idx = 0; idx < results.size(); idx ++) {
        total += results[idx] * expected[idx];
    }
    return total;
}
