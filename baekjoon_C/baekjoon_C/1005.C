#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int T; // 테스트케이스의 개수
int N, K;	// 건물의 개수, 건설 순서 개수 
int X, Y;
int D[1000];	// 건설 시간
int W;	// 목표 건물

int graph[1000][1000] = { 0, };
int calc = 0;
int max = -1;

void dfs(int node)
{
	calc += D[node];

	for (int i = 0; i < N ; i++)
	{
		if (graph[node][i] == 1)
		{
			dfs(i);
		}
	}
	
	if (max < calc)	// 계산값이 max 보다 클 경우 max값을 바꿈
	{
		max = calc;
	}

	calc -= D[node];
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		////// 입력 ///////
		scanf("%d %d", &N, &K);

		for (int j = 0; j < N; j++)
		{
			scanf("%d", &D[j]);
		}
		for (int j = 0; j < K; j++)
		{
			scanf("%d %d", &X, &Y);
			graph[Y-1][X-1] = 1;
		}
		
		scanf("%d", &W);

		////// 최소 시간 찾는 프로그램 ///////
		dfs(W - 1);
		printf("%d", max);
		
		/////// 초기화 /////////
		max = -1;
		calc = 0;
		for (int i = 0; i < N; i++)	// graph, visit 초기화
		{
			for (int j = 0; j < N; j++)
			{
				graph[i][j] = 0;
			}
		}

	}
	
}