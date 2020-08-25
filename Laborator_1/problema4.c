#include <stdio.h>

double nth_random_value(size_t n)
{
	if(n != 0)
		return 3.75 * nth_random_value(n - 1) * (1 - nth_random_value(n - 1));
	return 0.45;
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		printf("%.2lf ", nth_random_value(i));
	printf("\n");
	return 0;
}