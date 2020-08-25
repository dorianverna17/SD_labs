#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"
#include "list.h"

node_t *middle(node_t *node) {
  if(!node) {
    return node;
  } else {
    node_t *iter = node;
    node_t *iter_twise_fast = node;

    while(iter_twise_fast) {
      iter_twise_fast = iter_twise_fast->next;
      if (iter_twise_fast) {
        iter_twise_fast = iter_twise_fast->next;
      } else {
        break;
      }
      iter = iter->next;
    }
    return iter;
  }
}

static node_t* positive_index(node_t *node, int index) {
  while(node) {
    index -= 1;
    if (index < 0) {
      break;
    }
    node = node->next;
  }
  return node;
}

static node_t* negative_index(node_t *node, int index) {
  int steps = -index;
  node_t *iter = node;
  while(steps >= 1 && iter) {
    steps -= 1;
    iter = iter->next;
  }
  if (steps >= 1) {
    // not enough elements
    return NULL;
  }

  while(node && iter) {
    node = node->next;
    iter = iter->next;
  }
  return node;
}

node_t *index(node_t* node, int index) {
  if (index >= 0) {
    return positive_index(node, index);
  } else {
    return negative_index(node, index);
  }
}
