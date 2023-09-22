#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, v;
int arr[1001] = { 0, };
int visit[1001] = { 0, };
int edge[1001][1001];
int edgeflag[1001] = { 0, };
int arrlen = 0;

void dfs(int depth, int start)
{
	int i, j;

	arr[depth] = start;
	arrlen = depth;
	visit[start] = 1;
	for (i = 1; i <= n; i++)	// 오름차 순으로 숫자를 찾는다
	{
		for (j = 0; j < edgeflag[start]; j++)
		{
			if (i == edge[start][j])	// 오름차 순으로 숫자를 찾던 도중 현재 edge에 연결된 edge의 숫자가 나온다면 
			{
				if (visit[edge[start][j]] == 1)	// 이미 사용한 숫자이면 넘어간다
				{
					continue;
				}
				else
				{
					dfs(depth + 1, edge[start][j]);	// 다음 깊이로 넘어간다 / 시작 숫자를 정해준다
				}
			}
		}
	}


}

void bfs(int breadth, int start)
{
	int i, j, k;
	int flag = 0;

	arrlen = breadth;

	if (breadth == 0)
	{
		if (visit[start] == 0)
		{
			arr[breadth] = start;
			visit[start] = 1;
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (visit[i] == 1)
		{
			for (j = 1; j <= n; j++)
			{
				for (k = 0; k < edgeflag[i]; k++)
				{
					if (j == edge[i][k])
					{
						if (visit[j] == 0)
						{
							breadth++;
							arr[breadth] = j;
						}
					}
				}
			}
		}
	}

	for (i = 0; i <= breadth; i++)
	{
		if ((arr[i] != 0) && (visit[arr[i]] == 0))
		{
			visit[arr[i]] = 1;
			flag = 1;
		}
	}

	if (flag == 1)
	{
		dfs(breadth, start); // start값은 아무 값이나 주어도 됨
	}
}

int main()
{
	int i;
	int a, b;

	scanf("%d %d %d", &n, &m, &v);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		edge[a][edgeflag[a]] = b;
		edge[b][edgeflag[b]] = a;
		edgeflag[a]++;
		edgeflag[b]++;
	}

	dfs(0, v);
	for (i = 0; i <= arrlen; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	/////////////////// 초기화 //////////////////////
	for (i = 0; i < 1001; i++)
	{
		arr[i] = 0;
		visit[i] = 0;
	}
	arrlen = 0;
	//////////////////////////////////////////////////

	bfs(0, v);
	for (i = 0; i <= arrlen; i++)
	{
		printf("%d ", arr[i]);
	}
}