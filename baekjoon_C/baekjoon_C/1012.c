#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int t, m, n, k;
	int i, j;
	int xy[51][51] = { 0, };
	int visit[51][51] = { 0, };
	int x, y;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d %d", &m, &n, &k);
		for (j = 0; j < k; k++)
		{
			scanf("%d %d", &x, &y);
			xy[x][y] = 1;
		}
	}
}