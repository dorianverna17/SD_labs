#include "exercitiul1.h"

#include <queue>
#include <stdio.h>

void sort_using_pq_heaps(int *values, size_t length) {
	size_t i;
	std::priority_queue<int> coada_de_prioritati;
	for(i = 0; i < length; i++)
	{
		coada_de_prioritati.push(values[i]);
	}
	for(i = 0; i < length; i++)
	{
		values[length - i - 1] = coada_de_prioritati.top();
		coada_de_prioritati.pop();
	}
}