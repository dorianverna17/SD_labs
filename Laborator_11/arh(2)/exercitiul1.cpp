#include <math.h>
#include <stdio.h>

typedef struct graph {
	int V;
	int type;
	List *adjLists;
	int *visited;
	int *start, *end;
}*Graph;