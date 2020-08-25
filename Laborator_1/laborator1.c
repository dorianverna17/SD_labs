#include <stdio.h>

int count_equals(int value, int *vector, size_t vector_length)
{
	if(vector_length > 0)
		if(*vector == value)
			return 1 + count_equals(value, vector + 1, vector_length - 1);
		else
			return count_equals(value, vector + 1, vector_length - 1);
	return 0;
}
int main()
{
	int value, vector_length;
	scanf("%d", &value);
	scanf("%d", &vector_length);
	int vector[vector_length], i;
	for(i = 0; i < vector_length; i++)
	{
		scanf("%d", &vector[i]);
	}
	printf("%d\n", count_equals(value, vector, vector_length));
	return 0;
}