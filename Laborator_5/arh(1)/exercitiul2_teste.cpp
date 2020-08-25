#include <stdlib.h>
#include <numeric>

#include "helpers.h"
#include "dequeue.h"

extern char get_kth_digit(const int, const char);
extern void radix_sort(int vec[], const size_t length);

static float test_kth_digit() {
  std::vector<double> expected(5, 1.0 / 5.0);
  std::vector<double> results(expected.size(), 0.0);

  int x = 987654321;
  results[0] = get_kth_digit(x, 0) == 1;
  results[1] = get_kth_digit(x, 20) == 0;
  results[2] = get_kth_digit(x, 2) == 3;
  results[3] = get_kth_digit(x, 6) == 7;
  results[4] = get_kth_digit(x, 8) == 9;

  show_results(2.1, "kth_digit", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

static float test_radix_sort() {
  std::vector<double> expected(4, 1.0);
  std::vector<double> results(expected.size(), 0.0);

  std::vector<int> gv = generate_vec(0, 20, 0, 9999);
  int *v = new int[gv.size()];
  std::copy(gv.begin(), gv.end(), v);
  std::sort(gv.begin(), gv.end());
  radix_sort(v, gv.size());
  results[0] = compare_arrays(v, &gv[0], gv.size()) == 1;


  gv = generate_vec(0, 1000, 0, 9999);
  v = new int[gv.size()];
  std::copy(gv.begin(), gv.end(), v);
  std::sort(gv.begin(), gv.end());
  radix_sort(v, gv.size());
  results[1] = compare_arrays(v, &gv[0], gv.size());

  gv = generate_vec(0, 1000, 0, 9999);
  v = new int[gv.size()];
  std::copy(gv.begin(), gv.end(), v);
  std::sort(gv.begin(), gv.end());
  radix_sort(v, gv.size());
  results[2] = compare_arrays(v, &gv[0], gv.size());

  gv = generate_vec(0, 1000, 0, 9999);
  v = new int[gv.size()];
  std::copy(gv.begin(), gv.end(), v);
  std::sort(gv.begin(), gv.end());
  radix_sort(v, gv.size());
  results[3] = compare_arrays(v, &gv[0], gv.size());

  show_results(2.2, "sorting", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

#include <iostream>
float test_exercise2() {
  std::vector<double> expected = {1.0, 4.0};
  std::vector<double> results(2, 0);

  results[0] = test_kth_digit();
  results[1] = test_radix_sort();
  show_results(2.0, "radix", expected, results);

  double total = 0;
  for (size_t idx = 0; idx < results.size(); idx ++) {
    total += results[idx] * expected[idx];
  }
  return total;
}
