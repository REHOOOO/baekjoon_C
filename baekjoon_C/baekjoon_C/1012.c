#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int xy[51][51] = { 0, };
int visit[51][51] = { 0, };

void check(int j, int l)
{
	if (xy[j][l] == 1)
	{
		if (visit[j][l] == 0)
		{
			visit[j][l] = 1;
		}
	}

	if (xy[j + 1][l] == 1)
	{
		if (visit[j + 1][l] == 0)
		{
			check(j + 1, l);
		}
	}

	if (xy[j - 1][l] == 1)
	{
		if (visit[j - 1][l] == 0)
		{
			check(j - 1, l);
		}
	}

	if (xy[j][l + 1] == 1)
	{
		if (visit[j][l + 1] == 0)
		{
			check(j, l + 1);
		}
	}

	if (xy[j][l - 1] == 1)
	{
		if (visit[j][l - 1] == 0)
		{
			check(j, l - 1);
		}
	}
}

int main()
{
	int t, m, n, k;
	int i, j, l;
	int x, y;
	int cnt;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d %d", &m, &n, &k);

		//////// ÃÊ±âÈ­ ///////////
		for (j = 0; j < m; j++)
		{
			for (l = 0; l < n; l++)
			{
				xy[j][l] = 0;
				visit[j][l] = 0;
			}
		}
		///////////////////////////

		for (j = 0; j < k; j++)
		{
			scanf("%d %d", &x, &y);
			xy[x][y] = 1;
		}

		cnt = 0;

		for (j = 0; j < m; j++)
		{
			for (l = 0; l < n; l++)
			{
				if (xy[j][l] == 1)
				{
					if (visit[j][l] == 0)
					{
						check(j, l);
						cnt++;
					}
				}
			}
		}

		printf("%d\n", cnt);
	}
}