#include <stdio.h>

void process(int *vector, size_t *vector_len)
{
	int da;
	if(*vector_len != 1)
		if(*vector_len % 2 == 0)
			{
				da = *vector_len;
				*vector_len = da / 2;
				process(vector, vector_len);
				*vector_len = da / 2;
				process(vector + *vector_len, vector_len);
			}
		else
			{
				da = *vector_len;
				*vector_len = da / 2;
				process(vector, vector_len);
				*vector_len = da / 2; 
				process(vector + *vector_len + 1, vector_len);
			}
	else
		printf("%d ", *vector);
}
int main()
{
	int i;
	size_t vector_len;
	scanf("%ld", &vector_len);
	int vector[vector_len];
	for(i = 0; i < vector_len; i++)
		scanf("%d", &vector[i]);
	process(vector, &vector_len);
	printf("\n");
	return 0;
}