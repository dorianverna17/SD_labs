#include <stdio.h>

int control(int x)
{
	int s = 0;
	if(x > 9)
	{
		while(x != 0)
		{
			if((x % 10) % 2 == 0)
				s = s + (x % 10);
			x = x / 10;
		}
		x = s;
		control(x);
	}
	else
		printf("%d\n", x);
}
int main()
{
	int x;
	scanf("%d", &x);
	control(x);
	return 0;
}