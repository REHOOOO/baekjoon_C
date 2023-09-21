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
	int i,j;
	if (depth == n)	// 깊이가 m이면 현재까지 저장했던 수열을 출력
	{
		for (i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else
	{
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
	for (i = 0; i <= arrlen; i++)	// n개 만큼 숫자를 출력해준다 (만약 n보다 작
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}