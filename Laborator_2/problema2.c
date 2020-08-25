#include <stdio.h>

void greatest_common_divisor(unsigned a, unsigned b)
{
	if(a > b)
		greatest_common_divisor(a - b, b);
	else
		if(b > a)
			greatest_common_divisor(a, b - a);
		else
			printf("%d\n", a);
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	greatest_common_divisor(a, b);
	return 0;
}