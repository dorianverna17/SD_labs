#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

typedef struct node {
  void *data;
  size_t length;

  struct node *prev;
  struct node *next;
} node_t;

void *memdup(const void* data, const size_t length);
node_t *new_node(const void *data, const size_t length);
void print_list(node_t *node);

//exercise 1
void push_after(node_t *&current, node_t *new_node);
void push_front(node_t *&head, node_t *new_node);
void push_back(node_t *&head, node_t *new_node);

#endif
