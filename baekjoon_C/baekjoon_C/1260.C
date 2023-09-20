#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, v;
int arr[1001] = { 0, };
int visit[1001] = { 0, };
int edge[1001][1001];
int edgeflag[1001] = { 0, };

void dfs(int depth, int start)
{
	int i,j;
	if (depth == m)	// 깊이가 m이면 현재까지 저장했던 수열을 출력
	{
		for (i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = start; i <= n; i++)
		{
			if (visit[i] == 1)	// 이미 사용한 숫자이면 넘어간다
			{
				continue;
			}
			else
			{
				arr[depth] = i;	// 현재 깊이의 숫자는 i로 저장
				visit[i] = 1;	// 사용했다는 정보를 저장
				for (j = 0; j < edgeflag[i]; j++)
				{

				}
				dfs(depth + 1, i);	// 다음 깊이로 넘어간다 / 시작 숫자를 정해준다
				visit[i] = 0;	// 다음 깊이에서 작업이 끝나면 초기화 시켜준다
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
}