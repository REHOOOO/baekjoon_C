#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 1000

int T; // 테스트케이스의 개수
int N, K;	// 건물의 개수, 건설 순서 개수 
int X, Y;
int D[MAX];	// 건설 시간
int W;	// 목표 건물

int graph[MAX][MAX];
int dp[MAX];

int dfs(int node)
{
	if (dp[node] != -1)	// 이미 계산이 된 경우 
	{
		return dp[node];
	}

	dp[node] = D[node];

	for (int i = 0; i < N ; i++)
	{
		if (graph[i][node] == 1)	// i -> node로 연결된 경우
		{
			int time = dfs(i);	// 선행 노드들의 값을 가져옴
			if (dp[node] < time + D[node])	// 현재 저장 값보다 선행 노드들 값이 더 클 경우 
			{
				dp[node] = time + D[node]; // 현재 노드 값에 선행 노드들의 값을 더해서 저장
			}
		}
	}
	
	return dp[node];
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		/////// 초기화 /////////
		memset(graph, 0, sizeof(graph));
		memset(dp, -1, sizeof(dp));

		////// 입력 ///////
		scanf("%d %d", &N, &K);

		for (int j = 0; j < N; j++)
		{
			scanf("%d", &D[j]);
		}
		for (int j = 0; j < K; j++)
		{
			scanf("%d %d", &X, &Y);
			graph[X - 1][Y - 1] = 1;
		}
		
		scanf("%d", &W);

		////// 최소 시간 찾는 프로그램 ///////
		
		printf("%d\n", dfs(W - 1));
		

	}
	
}