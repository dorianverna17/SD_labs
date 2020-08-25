#include <stdio.h>

double power(int base, int pow)
{
	if(pow != 1)
		if(pow % 2 == 0)
			return power(base, pow / 2) * power(base, pow / 2);
		else
			return power(base, pow / 2) * power(base, pow / 2) * power(base, 1);
	return base;
}
int main()
{
	double base, pow;
	scanf("%lf", &base);
	scanf("%lf", &pow);
	printf("%.0lf\n", power(base, pow));
	return 0;
}