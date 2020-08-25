#include <stdlib.h>
#include <numeric>

#include "helpers.h"
#include "dequeue.h"

extern char *convert_to_postfix(const char *expression);
extern int evaluate(const char *postfix_expression);

static float test_infix_to_postifx() {
  std::vector<double> expected(3, 1.0);
  std::vector<double> results(expected.size(), 0.0);
  const char *expr = NULL;
  char *postfix = NULL;

  expr = "a+b*c";
  postfix = convert_to_postfix(expr);
  results[0] = postfix && (0 == strcmp(postfix, "abc*+"));

  expr = "(a+b)*c+(d-a)";
  postfix = convert_to_postfix(expr);
  results[1] = postfix && (0 == strcmp(postfix, "ab+c*da-+"));

  expr = "2+(9*3-(6/3^2)*1)*2";
  postfix = convert_to_postfix(expr);
  results[2] = postfix && (0 == strcmp(postfix, "293*632^/1*-2*+"));

  show_results(3.1, "postfix", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

static float test_postfix_eval() {
  std::vector<double> expected(2, 1.0);
  std::vector<double> results(expected.size(), 0.0);

  const char *expr = "231*+9-";
  results[0] = evaluate(expr) == -4;
  expr = "293*632^/1*-2*+";
  results[1] = evaluate(expr) == 54;

  show_results(3.2, "evaluate", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

float test_exercise3() {
  std::vector<double> expected = {3.0, 2.0};
  std::vector<double> results(expected.size(), 0);

  results[0] = test_infix_to_postifx();
  results[1] = test_postfix_eval();

  show_results(1.0, "infix_postfix", expected, results);
  double total = 0;
  for (size_t idx = 0; idx < results.size(); idx ++) {
    total += results[idx] * expected[idx];
  }
  return total;
}
