#ifndef __DEQUEUE_H__
#define __DEQUEUE_H__

#include "list.h"

#define ERROR_SUCCESS 0
#define ERROR_DEQUEUE_EMPTY -1
#define ERROR_DEQUEUE_INTERNAL -2

typedef struct {
  node_t *front;
  node_t *back;
  size_t length;
} dequeue_t;

dequeue_t init_deq();
dequeue_t *alloc_deq();
// acceseaza primul element
int front(dequeue_t *deq, double *value);
// acceseaza ultimul element
int back(dequeue_t *deq, double *value);
// insereaza un element in fata
int push_front(dequeue_t *deq, double value);
// insereaza un element in spate
int push_back(dequeue_t *deq, double value);
// scoate primul element
void pop_front(dequeue_t *deq);
// scoate ultimul element
void pop_back(dequeue_t *deq);
// intoarce numarul de elemente stocate in deq
size_t size(dequeue_t *deq);

#endif
