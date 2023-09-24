#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, v;
int visit[1001] = { 0, };
int edge[1001][1001];
int edgeflag[1001] = { 0, };
int queue[1001];

void dfs(int depth, int start)
{
	int i, j;

	printf("%d ", start);
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
	int front = 0;
	int rear = 0;
	int pop;
	int i,j;

	printf("%d ", start);
	queue[0] = start;
	rear++;
	visit[start] = 1;

	while (front < rear)
	{
		pop = queue[front];		// queue에 저장된 숫자를 가져온다 
		front++;

		for (i = 1; i <= n; i++)	// 오름차순으로 숫자를 찾는다
		{
			for (j = 0; j < edgeflag[pop]; j++)
			{
				if (i==edge[pop][j])	// 연결되는 엣지를 찾고
				{
					if (visit[i] == 0)	// 방문이 안된 엣지라면
					{
						printf("%d ", i);	// 출력
						queue[rear] = i;	// queue에 넣어준다
						rear++;
						visit[i] = 1;
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
	printf("\n");
	/////////////////// 초기화 //////////////////////
	for (i = 0; i < 1001; i++)
	{
		visit[i] = 0;
	}
	//////////////////////////////////////////////////

	bfs(0, v);
}