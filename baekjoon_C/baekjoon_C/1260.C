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
	//////////// 초기화 //////////////
	int i, j;
	for (i = 0; i < 1001; i++)
	{
		arr[i] = 0;
		visit[i] = 0;
	}
	arrlen = 0;
	/////////////////////////////////

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
	//////////// 초기화 //////////////
	int i, j;
	for (i = 0; i < 1001; i++)
	{
		arr[i] = 0;
		visit[i] = 0;
	}
	arrlen = 0;
	/////////////////////////////////

	if (breadth == 0)
	{
		arr[breadth] = start;
		visit[start] = 1;
	}
	
	for (i = 1; i <= n; i++) // arr에 현재 너비에 있는 숫자들 추가시켜주기
	{
		for (j = 0; j < edgeflag[start]; j++)	
		{
			if (i == edge[start][j])
			{
				if (visit[i] == 0)
				{
					breadth++;
					arr[breadth] = i;
					visit[i] = 1;
				}
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < edgeflag[start]; j++)	// 다음 edge들로 이동하기
		{
			if (i == edge[start][j])
			{
				
			}
		}
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

	
}