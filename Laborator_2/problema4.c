#include <stdio.h>

void swap(int* index1, int* index2)
{
	int temp = *index1;
	*index1 = *index2;
	*index2 = temp;
}
int partitie(int left, int right, double pivot, int *v)
{
	int leftPtr = left - 1;
	int rightPtr = right;
	while(1)
	{
		while(v[++leftPtr] < pivot);
		while(rightPtr > 0 && v[--rightPtr] > pivot);
		if(leftPtr >= rightPtr)
			break;
		else
			swap(&v[leftPtr], &v[rightPtr]);
	}
	swap(&v[leftPtr], &v[right]);
	return leftPtr;
}
void quicksort(int left, int right, int *v)
{
	if(right - left <= 0)
		return;
	else
	{
		double pivot = v[right];
		int partition = partitie(left, right, pivot, v);
		quicksort(left, partition - 1, v);
		quicksort(partition + 1, right, v);
	}
}
int main()
{
	int i, n;
	scanf("%d", &n);
	int v[n];
	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);
	quicksort(0, n - 1, v);
	for(i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}