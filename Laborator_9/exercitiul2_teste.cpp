#include <algorithm>
#include <stdlib.h>
#include <numeric>
#include <vector>

#include "helpers.h"
#include "scope_measurer.h"
#include "undirected_graph.h"

undirected_graph_t *prepare_graph(void);

void graph_traverse_DFS_recursive(undirected_graph_t * const graph,
    bool * const visited, const size_t start_node_id, visit_func_t func);

void graph_traverse_DFS_iterative(undirected_graph_t * const graph,
    const size_t start_node_id, visit_func_t func);

void graph_traverse_BFS(undirected_graph_t * const graph,
    const size_t start_node_id, visit_func_t func);


static std::vector<int> nodes_in_order_dsf_rec;

static double visit_func_dfs_rec(const size_t node_id) {
    //printf("%zd\n", node_id);
    nodes_in_order_dsf_rec.push_back(node_id);
    return 0.0;
}

static float test_dfs_recursive() {
    const size_t test_count = 1;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();

    int gt[] = {9, 1, 0, 2, 3, 4, 8, 5, 6, 7};
    bool *visited = (bool *)calloc(graph->node_count, sizeof(bool));
    graph_traverse_DFS_recursive(graph, visited, 9, visit_func_dfs_rec);
    results[0] = nodes_in_order_dsf_rec.size() > 0
        && compare_arrays(gt, &nodes_in_order_dsf_rec[0],
                            sizeof(gt) / sizeof(gt[0]));

    show_results(2.1, "test dfs recursive", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}

static std::vector<int> nodes_in_order_dsf_iter;

static double visit_func_dfs_iter(const size_t node_id) {
    //printf("* %zd\n", node_id);
    nodes_in_order_dsf_iter.push_back(node_id);
    return 0.0;
}

static float test_dfs_iterative() {
    const size_t test_count = 1;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();

    int gt[] = {4, 9, 8, 7, 6, 5, 1, 3, 2, 0};
    graph_traverse_DFS_iterative(graph, 4, visit_func_dfs_iter);
    results[0] = nodes_in_order_dsf_iter.size() > 0
        && compare_arrays(gt, &nodes_in_order_dsf_iter[0],
                            sizeof(gt) / sizeof(gt[0]));

    show_results(2.2, "test dfs iterative", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}

static std::vector<int> nodes_in_order_bfs_iter;

static double visit_func_bfs_iter(const size_t node_id) {
    //printf("%zd ", node_id);
    nodes_in_order_bfs_iter.push_back(node_id);
    return 0.0;
}

static float test_bfs_iterative() {
    const size_t test_count = 1;
    const float points = 1.0;
    std::vector<double> expected(test_count, points / test_count);
    std::vector<double> results(expected.size(), 0.0);

    undirected_graph_t *graph = prepare_graph();

    int gt[] = {9, 1, 4, 8, 0, 2, 3, 5, 6, 7};
    graph_traverse_BFS(graph, 9, visit_func_bfs_iter);
    results[0] = nodes_in_order_bfs_iter.size() > 0
        && compare_arrays(gt, &nodes_in_order_bfs_iter[0],
                        sizeof(gt) / sizeof(gt[0]));

    show_results(2.2, "test bfs iterative", expected, results);
    return std::accumulate(results.begin(), results.end(), 0.0)
        / results.size();
}


float test_exercise2(void) {
    std::vector<double> expected = {1.0, 1.0, 1.0};
    std::vector<double> results(expected.size(), 0);

    results[0] = test_dfs_recursive();
    results[1] = test_dfs_iterative();
    results[2] = test_bfs_iterative();

    show_results(2.0, "graph traversals", expected, results);
    double total = 0;
    for (size_t idx = 0; idx < results.size(); idx ++) {
        total += results[idx] * expected[idx];
    }
    return total;
}
