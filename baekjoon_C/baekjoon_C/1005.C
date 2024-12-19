#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int graph[1000][1000] = { 0, };
int visit[1000] = { 0, };

int dfs(int node)
{
	visit[node] = 1;

	for (int i = node-1; i >= 0 ; i--)
	{
		if (graph[node][i] == 1 && !visit[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	int T;
	int N, K;
	int D[1000];
	int X, Y;
	
	int W;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		////// ют╥б ///////
		scanf("%d %d", &N, &K);

		for (int j = 0; j < N; j++)
		{
			scanf("%d", &D[j]);
		}
		for (int j = 0; j < K; j++)
		{
			scanf("%d %d", &X, &Y);
			graph[X-1][Y-1] = 1;
			graph[Y-1][X-1] = 1;
		}
		
		scanf("%d", &W);


	}
	
}