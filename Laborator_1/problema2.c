#include <stdio.h>

int fibonacci(int k)
{
	if(k == 0)
		return 0;
	if(k - 1 > 0)
		if(k - 2 > 0)
			return fibonacci(k - 1) + fibonacci(k - 2);
		else
			return fibonacci(k - 1);
	return 1;
}
int main()
{
	int k;
	scanf("%d", &k);
	printf("%d\n", fibonacci(k));
	return 0;
}