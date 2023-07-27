#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int plane[100][100] = { 0, };

	int i, j, k;
	int x1, x2, y1, y2;
	int cnt = 0;

	for (i = 0; i < 4; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (j = x1; j < x2; j++)
		{
			for (k = y1; k < y2; k++)
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