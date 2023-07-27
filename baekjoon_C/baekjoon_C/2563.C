#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int plane[100][100] = { 0, };

	int i, j, k;
	int x, y;
	int cnt = 0;
	int n;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		for (j = x; j < x + 10; j++)
		{
			for (k = y; k < y + 10; k++)
			{
				if (plane[j][k] == 0)
				{
					cnt = cnt + 1;
					plane[j][k] = 1;
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}