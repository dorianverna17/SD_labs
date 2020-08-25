#include "list.h"
#include "helpers.h"
#include "dequeue.h"

dequeue_t init_deq(void) {
  dequeue_t q = {
      .front = NULL,
      .back = NULL,
      .length = 0
  };
  return q;
}

dequeue_t *alloc_deq(void) {
  return NULL;
}

// acceseaza primul element
int front(dequeue_t *deq, double *value) {
  return ERROR_DEQUEUE_INTERNAL;
}

// acceseaza ultimul element
int back(dequeue_t *deq, double *value) {
  return ERROR_DEQUEUE_INTERNAL;
}

// insereaza un element in fata
int push_front(dequeue_t *deq, double value) {
  return ERROR_DEQUEUE_INTERNAL;
}

// insereaza un element in spate
int push_back(dequeue_t *deq, double value) {
  return ERROR_DEQUEUE_INTERNAL;
}

// scoate primul element
void pop_front(dequeue_t *deq) {

}

// scoate ultimul element
void pop_back(dequeue_t *deq) {

}

// intoarce numarul de elemente stocate in deq
size_t size(dequeue_t *deq) {
  return 0;
}
