#include <stdlib.h>
#include <numeric>

#include "helpers.h"
#include "dequeue.h"

static float test_init() {
  std::vector<double> expected = {1.0};
  std::vector<double> results(expected.size(), 0);

  dequeue_t *q2 = alloc_deq();
  results[0] = (q2 != NULL);

  show_results(1.1, "init", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0);
}

static float test_insert() {
  std::vector<double> expected(12, 1.0 / 12.0);
  std::vector<double> results(expected.size(), 0.0);

  dequeue_t *q1 = alloc_deq();
  push_front(q1, 20.0);
  results[0] = q1 && (q1->front != NULL) && AS(double, q1->front->data) == 20.0;
  results[1] = q1 && (q1->back != NULL) && AS(double, q1->back->data) == 20.0;
  push_front(q1, 25.0);
  results[2] = q1 && (q1->front != NULL) && AS(double, q1->front->data) == 25.0;
  results[3] = q1 && (q1->back != NULL) && AS(double, q1->back->data) == 20.0;

  dequeue_t *q2 = alloc_deq();
  push_back(q2, 20.0);
  results[4] = q2 && (q2->back != NULL) && AS(double, q2->back->data) == 20.0;
  results[5] = q2 && (q2->front != NULL) && AS(double, q2->front->data) == 20.0;
  push_back(q2, 25.0);
  results[6] = q2 && (q2->back != NULL) && AS(double, q2->back->data) == 25.0;
  results[7] = q2 && (q2->front != NULL) && AS(double, q2->front->data) == 20.0;

  push_front(q2, 15.0);
  results[8] = q2 && (q2->front != NULL) && AS(double, q2->front->data) == 15.0;
  results[9] = q2 && (q2->back != NULL) && AS(double, q2->back->data) == 25.0;
  push_back(q2, 45.0);
  results[10] = q2 && (q2->back != NULL) && AS(double, q2->back->data) == 45.0;
  results[11] = q2 && (q2->front != NULL) && AS(double, q2->front->data) == 15.0;

  show_results(1.2, "insert", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

static float test_peek() {
  std::vector<double> expected(11, 1.0 / 11.0);
  std::vector<double> results(expected.size(), 0);

  dequeue_t *q1 = alloc_deq();
  results[0] = (q1 != NULL);

  double value1 = 0, value2 = 0;
  int err_code = front(q1, &value1);
  results[1] = (err_code == ERROR_DEQUEUE_EMPTY);

  push_front(q1, 1.0);
  err_code = front(q1, &value1);
  results[2] = (err_code == ERROR_SUCCESS) && (value1 == 1.0);
  err_code = back(q1, &value2);
  results[3] = (err_code == ERROR_SUCCESS) && (value2 == 1.0);

  push_back(q1, 11.0);
  err_code = front(q1, &value1);
  results[4] = (err_code == ERROR_SUCCESS) && (value1 == 1.0);
  err_code = back(q1, &value2);
  results[5] = (err_code == ERROR_SUCCESS) && (value2 == 11.0);
  push_front(q1, 2.0);
  push_back(q1, 12.0);
  push_front(q1, 3.0);
  push_back(q1, 13.0);
  push_front(q1, 4.0);
  push_back(q1, 14.0);
  push_front(q1, 5.0);
  push_back(q1, 15.0);
  err_code = front(q1, &value1);
  results[6] = (err_code == ERROR_SUCCESS) && (value1 == 5.0);
  err_code = back(q1, &value2);
  results[7] = (err_code == ERROR_SUCCESS) && (value2 == 15.0);

  dequeue_t *q2 = alloc_deq();
  results[8] = (q1 != NULL);

  push_back(q2, 1.0);
  err_code = front(q2, &value1);
  results[9] = (err_code == ERROR_SUCCESS) && (value1 == 1.0);
  err_code = back(q2, &value2);
  results[10] = (err_code == ERROR_SUCCESS) && (value2 == 1.0);

  show_results(1.3, "peek", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}

static float test_pop() {
  std::vector<double> expected(14, 1.0 / 14.0);
  std::vector<double> results(expected.size(), 0);

  int err_code = 0;
  double value1 = 0, value2 = 0;
  dequeue_t *q1 = alloc_deq();

  push_front(q1, 1.0);
  push_back(q1, 11.0);
  push_front(q1, 2.0);
  push_back(q1, 12.0);
  err_code = front(q1, &value1);
  results[0] = q1 && (err_code == ERROR_SUCCESS) && (value1 == 2.0);
  err_code = back(q1, &value2);
  results[1] = q1 && (err_code == ERROR_SUCCESS) && (value2 == 12.0);

  pop_front(q1);
  err_code = front(q1, &value1);
  results[2] = q1 && (err_code == ERROR_SUCCESS) && (value1 == 1.0);
  err_code = back(q1, &value2);
  results[3] = q1 && (err_code == ERROR_SUCCESS) && (value2 == 12.0);

  pop_back(q1);
  err_code = front(q1, &value1);
  results[4] = q1 && (err_code == ERROR_SUCCESS) && (value1 == 1.0);
  err_code = back(q1, &value2);
  results[5] = q1 && (err_code == ERROR_SUCCESS) && (value2 == 11.0);

  pop_back(q1);
  err_code = front(q1, &value1);
  results[6] = q1 && (err_code == ERROR_SUCCESS) && (value1 == 1.0);
  err_code = back(q1, &value2);
  results[7] = q1 && (err_code == ERROR_SUCCESS) && (value2 == 1.0);

  pop_back(q1);
  err_code = front(q1, &value1);
  results[8] = q1 && (err_code == ERROR_DEQUEUE_EMPTY);
  err_code = back(q1, &value2);
  results[9] = q1 && (err_code == ERROR_DEQUEUE_EMPTY);
  results[10] = q1 && (q1->front == q1->back && !q1->front);

  push_back(q1, 20.0);
  pop_front(q1);
  err_code = front(q1, &value1);
  results[11] = q1 && (err_code == ERROR_DEQUEUE_EMPTY);
  err_code = back(q1, &value2);
  results[12] = q1 && (err_code == ERROR_DEQUEUE_EMPTY);
  results[13] = q1 && (q1->front == q1->back && !q1->front);

  show_results(1.4, "pop", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}


static float test_size() {
  std::vector<double> expected(5, 1.0 / 5.0);
  std::vector<double> results(expected.size(), 0.0);

  dequeue_t *q1 = alloc_deq();
  results[0] = q1 && size(q1) == 0;
  push_front(q1, 20.0);
  results[1] = q1 && size(q1) == 1;
  push_front(q1, 25.0);
  results[2] = q1 && size(q1) == 2;

  pop_back(q1);
  results[3] = q1 && size(q1) == 1;
  pop_front(q1);
  results[4] = q1 && size(q1) == 0;

  show_results(1.5, "size", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0) / results.size();
}



float test_exercise1() {
  std::vector<double> expected = {1.0, 1.0, 1.0, 1.0, 1.0};
  std::vector<double> results(5, 0);

  results[0] = test_init();
  results[1] = test_insert();
  results[2] = test_peek();
  results[3] = test_pop();
  results[4] = test_size();

  show_results(1.0, "dequeue_t", expected, results);
  return std::accumulate(results.begin(), results.end(), 0.0);
}
