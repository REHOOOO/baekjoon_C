#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int t, m, n, k;
	int i, j, l;
	int xy[51][51] = { 0, };
	int visit[51][51] = { 0, };
	int x, y;
	int cnt;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d %d", &m, &n, &k);
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
					if (visit[j][l] == 0 && visit[j - 1][l] == 0 && visit[j][l - 1] == 0 && visit[j + 1][l] == 0 && visit[j][l + 1] == 0)
					{
						cnt++;
						visit[j][l] = 1;
					}
					else
					{
						visit[j][l] = 1;
					}
				}
			}
		}

		printf("%d\n", cnt);
	}
}