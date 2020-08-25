#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void insert_sorted(node_t **node, double data, compare_t cmp) {
  if (!node) {
    node_t *n = new_node(data, NULL);
    *node = n;
  } else if (cmp(&(*node)->data, &data) >= 0) {
    insert_sorted(&(*node)->next, data, cmp);
  } else {
    push_front(node, data);
  }
}

node_t *merge_sorted(node_t **node1, node_t **node2, compare_t cmp) {
  if (!node1) {
    return *node2;
  } else if (!node2) {
    return *node1;
  } else if (cmp(&(*node1)->data, &(*node2)->data) > 0) {
    (*node1)->next = merge_sorted(&(*node1)->next, node2, cmp);
    return *node1;
  }  else {
    (*node2)->next = merge_sorted(node1, &(*node2)->next, cmp);
    return *node2;
  }
}
