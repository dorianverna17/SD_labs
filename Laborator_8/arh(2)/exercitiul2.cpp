#include <string.h>
#include <stdio.h>

#include "heap.h"
#include "helpers.h"

void percolate_up(binary_heap_t * const heap, int current)
{
	int aux;
	while(heap->values[current] < heap->values[((current-1) / 2)])
	{
		aux = heap->values[current];
		heap->values[current] = heap->values[((current-1) / 2)];
		heap->values[((current-1) / 2)] = aux;
		current = (current-1) / 2;
	}
}

void heap_push(binary_heap_t * const heap, const int value) {
	if(heap->length < heap->capacity)
	{
		heap->values[heap->length++] = value;
		percolate_up(heap, heap->length - 1);
	}
}

void percolate_down(binary_heap_t * const heap, int current)
{
	int minimum_child_idx = current;
	int left_child = 2 * current + 1;
	int right_child = 2 * current + 2;
	if(size_t(left_child) < heap->length
		&& heap->values[minimum_child_idx] > heap->values[left_child])
		minimum_child_idx = left_child;
	if(size_t(right_child) < heap->length
		&& heap->values[minimum_child_idx] > heap->values[right_child])
		minimum_child_idx = right_child;
	if(minimum_child_idx != current) {
	int aux;
	aux = heap->values[current];
	heap->values[current] = heap->values[minimum_child_idx];
	heap->values[minimum_child_idx] = aux;
	percolate_down(heap, minimum_child_idx);
	}
}

int heap_top(binary_heap_t const * heap) {
	if(heap->length != 0)
    	return heap->values[0];
    return -1;
}

void heap_pop(binary_heap_t * const heap) {
	int aux;
	aux = heap->values[0];
	heap->values[0] = heap->values[heap->length - 1];
	heap->values[heap->length - 1] = aux;
	heap->length--;
	percolate_down(heap, 0);
}
