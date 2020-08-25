#include "heap.h"
#include "helpers.h"

void percolate_down2(binary_heap_t * const heap, int current)
{
	size_t minimum_child_idx = current;
	size_t left_child = 2 * current + 1;
	size_t right_child = 2 * current + 2;
	if(left_child < heap->length
		&& heap->values[minimum_child_idx] > heap->values[left_child])
		minimum_child_idx = left_child;
	if(right_child < heap->length
		&& heap->values[minimum_child_idx] > heap->values[right_child])
		minimum_child_idx = right_child;
	if(minimum_child_idx != size_t(current)) {
	int aux;
	aux = heap->values[current];
	heap->values[current] = heap->values[minimum_child_idx];
	heap->values[minimum_child_idx] = aux;
	percolate_down2(heap, minimum_child_idx);
	}
}

void percolate_up1(binary_heap_t * const heap, int current)
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

void heap_remove(binary_heap_t * const heap, const int value) {
	size_t i, current;
	for(i = 0; i < (heap->length); i++)
	{
		if(heap->values[i] == value)
			current = i;
	}
	int aux = heap->values[current];
	heap->values[current] = heap->values[heap->length - 1];
	heap->values[heap->length - 1] = aux;
	heap->length--;
	percolate_down2(heap, current);
	percolate_up1(heap, current);
}
