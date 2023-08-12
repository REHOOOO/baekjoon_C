#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int graph[100][100] = { 0, };
	int visit[100] = { 0, };
	visit[0] = 1;
	int com, num, c1, c2;
	int i, j, k;
	int cnt = -1;

	scanf("%d", &com);
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &c1, &c2);
		c1 = c1 - 1;
		c2 = c2 - 1;
		graph[c1][c2] = 1;
		graph[c2][c1] = 1;
	}

	for (k = 0; k < com; k++)
	{
		for (i = 0; i < com; i++)
		{
			for (j = 0; j < com; j++)
			{
				if (visit[i] == 1 || visit[j] == 1)
				{
					if (graph[i][j] == 1 || graph[j][i] == 1)
					{
						visit[i] = 1;
						visit[j] = 1;
					}
				}
			}
		}
	}
	

	for (i = 0; i < com; i++)
	{
		if (visit[i] == 1)
		{
			cnt = cnt + 1;
		}
	}

	printf("%d", cnt);

	return 0;
}