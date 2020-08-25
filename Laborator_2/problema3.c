#include <stdio.h>
#include <math.h>

double binary(double base, double begin, double end)
{
	double mid;
	if(begin - end > 0.001)
		return -1;
	mid = (double)(begin + end) / 2;
	if(fabs(mid * mid - base) < 0.001)
		return mid;
	if(base > 1)
		{
			if(base - mid * mid > 0.001)
				return binary(base, mid, end);
			return binary(base, begin, mid);
		}
}
double my_sqrt(double base)
{
	if(base > 0)
	{
		if(base > 1)
		{
			return(binary(base, 1, base));
		}
		else
			if(base == 1)
				return 1;
			else
				return(binary(base, 0, 1));
	}
	else
	{
		return -1;
		printf("Nu se poate calcula radical\n");
	}
}
int main()
{
	double base;
	scanf("%lf", &base);
	printf("%lf\n", my_sqrt(base));
	return 0;
}