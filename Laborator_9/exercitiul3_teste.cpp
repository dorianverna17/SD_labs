#include <stdlib.h>
#include <numeric>

#include "helpers.h"
#include "scope_measurer.h"
#include "undirected_graph.h"

#define DEBUG_VERBOSE 0
#define GRAPH_BIG_PATH "graph_big.csv"
#define GRAPH_HUGE_PATH "graph_huge.csv"

undirected_graph_t *prepare_graph(void);

int *shortest_path(undirected_graph_t * const graph,
    const size_t source_id,
    const size_t destination_id);

static float test_shortest_path_case1() {
    const size_t test_count = 1;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();
    int gt[] = {6, 8, 9, 1, 2};
    int *path = shortest_path(graph, 6, 2);

    results[0] = path != NULL
        && compare_arrays(gt, path, sizeof(gt) / sizeof(gt[0]));

    show_results(3.1, "shortest path 6 to 2", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}

static float test_shortest_path_case2() {
    const size_t test_count = 1;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();
    int gt[] = {5, 8, 9, 4};
    int *path = shortest_path(graph, 5, 4);

    results[0] = path != NULL
        && compare_arrays(gt, path, sizeof(gt) / sizeof(gt[0]));

    show_results(3.1, "shortest path 5 to 4", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}

static float test_shortest_path_impossible() {
    const size_t test_count = 2;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();
    graph_remove_edge(graph, 9, 8);
    graph_remove_edge(graph, 1, 0);
    graph_remove_edge(graph, 1, 5); // nothing should change

    int *path =  shortest_path(graph, 3, 4);
    results[0] = path != NULL;

    path = shortest_path(graph, 5, 2);
    results[0] = results[0] > 0
        && (path == NULL);

    path = shortest_path(graph, 7, 0);
    results[1] = results[0] > 0
        && (path == NULL);

    show_results(3.1, "shortest path non existent", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}

static float test_shortest_path_huge() {
    const size_t test_count = 3;
    const float points = 2.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    ScopeMeasurer measurer = ScopeMeasurer();

    undirected_graph_t *graph = graph_load(GRAPH_BIG_PATH);
    measurer.startMeasure();
    int *path = shortest_path(graph, 15, 180);
    measurer.finishMeasure();

    if (path && DEBUG_VERBOSE) {
        print_vector(path, -1);
    }

    int gt[] = {15, 184, 66, 105, 96, 53, 5, 8, 109, 166, 58, 73, 180};
    results[0] = path != NULL
        && compare_arrays(gt, path, sizeof(gt) / sizeof(gt[0]));

    graph = graph_load(GRAPH_HUGE_PATH);
    measurer.startMeasure();
    path = shortest_path(graph, 70, 227);
    measurer.finishMeasure();

    if (path && DEBUG_VERBOSE) {
        print_vector(path, -1);
    }

    int gt2[] = {70, 351, 152, 496, 257, 415, 436, 227};
    results[1] = path != NULL
        && compare_arrays(gt2, path, sizeof(gt2) / sizeof(gt2[0]));

    results[2] = results[0] > 0.0
        && results[1] > 0.0
        && (measurer.getTotalTime() <= 0.01);

    show_results(3.1, "shortest path huge", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}


float test_exercise3() {
    std::vector<double> expected = {1.0, 1.0, 1.0, 2.0};
    std::vector<double> results(expected.size(), 0);

    results[0] = test_shortest_path_case1();
    results[1] = test_shortest_path_case2();
    results[2] = test_shortest_path_impossible();
    results[3] = test_shortest_path_huge();

    show_results(3.0, "shortest path", expected, results);
    double total = 0;
    for (size_t idx = 0; idx < results.size(); idx ++) {
        total += results[idx] * expected[idx];
    }
    return total;
}
