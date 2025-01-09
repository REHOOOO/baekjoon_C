#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int memory[100];
int cost[100];

int main()
{
	int N, M;	// 앱의 개수, 확보해야 하는 메모리 
	int max_cost = 0;	// 최대 비용

	///// 입력 /////
	scanf("%d %d", &N, &M);
	for (int i=0; i < N; i++)
	{
		scanf("%d", &memory[i]);
	}
	for (int i=0; i < N; i++)
	{
		scanf("%d", &cost[i]);
		max_cost += cost[i];
	}

	// dp 배열 초기화
	int* dp = (int*)malloc(sizeof(int)*(max_cost+1));
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < N; i++)
	{
		for (int j = max_cost; j >= cost[i]; j--)	// j가 현재 i의 비용보다 작아질때 까지 반복
		{
			dp[j] = MAX(dp[j], dp[j - cost[i]] + memory[i]);
			// 현재 j(cost 합)에 올 수 있는 가장 큰 메모리 값을 저장해 준다
			// dp[j - cost[i]]는 현재 앱이 실행하지 않을 때의 최대 메모리 값을 말한다 (반복문이 돌면서 계속 채워나간다)
			// 그 메모리 값에 현재 메모리 값을 더해 계산 
		}
	}

	for (int i = 0; i <= max_cost; i++)
	{
		if (dp[i] >= M)	// 낮은 cost부터 확인하다 원하는 메모리 크기보다 커지면
		{
			printf("%d", i);
			break;
		}
	}

	free(dp);	// dp 해제 
	return 0;
}