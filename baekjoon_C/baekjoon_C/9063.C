#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int x, y;
	int xmax=-20000;
	int ymax=-20000;
	int xmin=20000;
	int ymin=20000;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);

		if (x > xmax)
		{
			xmax = x;
		}

		if (x < xmin)
		{
			xmin = x;
		}

		if (y > ymax)
		{
			ymax = y;
		}

		if (y < ymin)
		{
			ymin = y;
		}
	}

	printf("%d", (xmax - xmin) * (ymax - ymin));

	return 0;
}