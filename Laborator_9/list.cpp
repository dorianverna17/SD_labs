#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include <stdlib.h>
#include <string.h>

void *memdup(const void* data, const size_t length) {
    void *data_copy = calloc(length, 1);
    memmove(data_copy, data, length);
    return data_copy;
}

node_t *new_node(const void *data, const size_t length) {
  node_t *node = (node_t *)calloc(1, sizeof(*node));
  node->data = memdup(data, length);
  node->length = length;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void print_list(node_t *node) {
  if (!node){
    printf("[]");
    return;
  }
  int list_limit = 100;
  printf("[");
  for (node_t *iterator = node; iterator != NULL; iterator = iterator->next) {
      printf("%c", (char)*(double *)iterator->data);
      if (iterator->next)
          printf(", ");
      if (list_limit-- < 0) {
        break;
      }
  }
  printf("]\n");

  if (list_limit < 0) {
    printf("[Warning] the list was too long or there was a cycle?!\n");
  }
}

int get_int_value(const node_t *node) {
  if (!node) {
    return 0;
  }
  return *(int *)node->data;
}

void push_after(node_t *&current, node_t *new_node) {
  if (!current || !new_node) {
    return;
  }

  if (new_node->next || new_node->prev) {
    printf("[push_after] new_node already has some links\n");
  }

  new_node->next = current->next;
  new_node->prev = current;

  if (current->next)
    current->next->prev = new_node;

  current->next = new_node;
}

void push_front(node_t *&head, node_t *new_node) {
  if (!new_node) {
    return;
  } else if (!head) {
    head = new_node;
  } else {
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
  }
}

void push_back(node_t *&head, node_t *new_node) {
  if (!new_node) {
    return;
  } else if (!head) {
    head = new_node;
  } else {
    node_t *iterator = head;
    while(iterator->next) {
      iterator = iterator->next;
    }
    new_node->prev = iterator;
    iterator->next = new_node;
  }
}
