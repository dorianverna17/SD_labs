#include <stdlib.h>
#include <numeric>

#include "undirected_graph.h"
#include "helpers.h"

undirected_graph_t *prepare_graph(void) {
    undirected_graph_t *graph = alloc_undirected_graph(10);

    graph_insert_edge(graph, 0, 1);
    graph_insert_edge(graph, 1, 2);
    graph_insert_edge(graph, 1, 3);
    graph_insert_edge(graph, 1, 9);
    graph_insert_edge(graph, 2, 3);
    graph_insert_edge(graph, 3, 4);
    graph_insert_edge(graph, 4, 9);
    graph_insert_edge(graph, 5, 8);
    graph_insert_edge(graph, 6, 7);
    graph_insert_edge(graph, 6, 8);
    graph_insert_edge(graph, 7, 8);
    graph_insert_edge(graph, 8, 9);
    return graph;
}

static float test_add_edge() {
    const size_t test_count = 3;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();

    results[0] = graph_is_edge(graph, 0, 1)
        && graph_is_edge(graph, 1, 2)
        && graph_is_edge(graph, 1, 3)
        && graph_is_edge(graph, 1, 9)
        && graph_is_edge(graph, 2, 3)
        && graph_is_edge(graph, 3, 4)
        && graph_is_edge(graph, 4, 9)
        && graph_is_edge(graph, 5, 8)
        && graph_is_edge(graph, 6, 7)
        && graph_is_edge(graph, 6, 8)
        && graph_is_edge(graph, 7, 8)
        && graph_is_edge(graph, 8, 9);

    results[1] = results[0] > 0.0
        && graph_is_edge(graph, 1, 0)
        && graph_is_edge(graph, 2, 1)
        && graph_is_edge(graph, 3, 1)
        && graph_is_edge(graph, 9, 1)
        && graph_is_edge(graph, 3, 2)
        && graph_is_edge(graph, 4, 3)
        && graph_is_edge(graph, 9, 4)
        && graph_is_edge(graph, 8, 5)
        && graph_is_edge(graph, 7, 6)
        && graph_is_edge(graph, 8, 6)
        && graph_is_edge(graph, 8, 7)
        && graph_is_edge(graph, 9, 8);


    results[2] = results[1] > 0.0
        && !graph_is_edge(graph, 0, 2)
        && !graph_is_edge(graph, 0, 5)
        && !graph_is_edge(graph, 0, 7)
        && !graph_is_edge(graph, 1, 4)
        && !graph_is_edge(graph, 4, 7)
        && !graph_is_edge(graph, 4, 2)
        && !graph_is_edge(graph, 5, 9)
        && !graph_is_edge(graph, 2, 7)
        && !graph_is_edge(graph, 4, 6)
        && !graph_is_edge(graph, 5, 1);

    show_results(1.1, "test insert edge", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}

static float test_remove_edge() {
    const size_t test_count = 2;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();

    graph_remove_edge(graph, 9, 8);
    graph_remove_edge(graph, 0, 1);

    results[0] = !graph_is_edge(graph, 0, 1)
        && graph_is_edge(graph, 1, 2)
        && graph_is_edge(graph, 1, 3)
        && graph_is_edge(graph, 1, 9)
        && graph_is_edge(graph, 2, 3)
        && graph_is_edge(graph, 3, 4)
        && graph_is_edge(graph, 4, 9)
        && graph_is_edge(graph, 5, 8)
        && graph_is_edge(graph, 6, 7)
        && graph_is_edge(graph, 6, 8)
        && graph_is_edge(graph, 7, 8)
        && !graph_is_edge(graph, 8, 9)
        && !graph_is_edge(graph, 1, 0)
        && graph_is_edge(graph, 2, 1)
        && graph_is_edge(graph, 3, 1)
        && graph_is_edge(graph, 9, 1)
        && graph_is_edge(graph, 3, 2)
        && graph_is_edge(graph, 4, 3)
        && graph_is_edge(graph, 9, 4)
        && graph_is_edge(graph, 8, 5)
        && graph_is_edge(graph, 7, 6)
        && graph_is_edge(graph, 8, 6)
        && graph_is_edge(graph, 8, 7)
        && !graph_is_edge(graph, 9, 8);

    results[1] = results[0] > 0.0
        && !graph_is_edge(graph, 0, 2)
        && !graph_is_edge(graph, 0, 5)
        && !graph_is_edge(graph, 0, 7)
        && !graph_is_edge(graph, 1, 4)
        && !graph_is_edge(graph, 4, 7)
        && !graph_is_edge(graph, 4, 2)
        && !graph_is_edge(graph, 5, 9)
        && !graph_is_edge(graph, 2, 7)
        && !graph_is_edge(graph, 4, 6)
        && !graph_is_edge(graph, 5, 1);

    show_results(1.2, "test remove edge", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}


float test_exercise1(void) {
    std::vector<double> expected(2, 2.0 / 2.0);
    std::vector<double> results(expected.size(), 0);

    results[0] = test_add_edge();
    results[1] = test_remove_edge();

    show_results(1.0, "undirected_graph", expected, results);
    double total = 0;
    for (size_t idx = 0; idx < results.size(); idx ++) {
        total += results[idx] * expected[idx];
    }
    return total;
}
