#include <stdio.h>
#include <math.h>

double binary(double base, double begin, double end)
{
	double mid;
	if(begin - end > 0.001)
		return -1;
	mid = (begin + end) / 2;
	if(fabs(exp(mid) - base) < 0.001)
		return mid;
	if(base - exp(mid) > 0.001)
		return binary(base, mid, end);
	return binary(base, begin, mid);
}
double my_ln(double base)
{
	if(base == 1)
		return 0;
	if(base > 1)
		return binary(base, 0, base - 1);
	return binary(base, -1, base - 1);	
}
int main()
{
	double x;
	scanf("%lf", &x);
	printf("%lf\n", my_ln(x));
}