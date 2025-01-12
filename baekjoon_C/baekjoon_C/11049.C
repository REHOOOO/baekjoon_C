#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 999999999
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int main()
{
	int N;
	int size[500][2];
	int dp[500][500];
	///// 입력 /////
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &size[i][0], &size[i][1]);
	}


	///// dp 초기화 //////
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = INF;	
		}
		dp[i][i] = 0;	// 계산이 필요 없음 
	}
	
	///// 계산 /////
	for (int len = 2; len <= N; len++)	// 행렬 곱셈 길이 
	{
		for (int i = 0; i <= N - len; i++)	// 현재 곱셈 길이에 맞추어 for문 
		{
			int j = i + len - 1;	// 끝 지점 설정 (i 시작지점, j 끝지점)
			for (int k = i; k < j; k++)	// 내부 계산 
			{
				dp[i][j] = MIN(dp[i][j], dp[i][k] + dp[k + 1][j] + size[i][0] * size[k][1] * size[j][1]);
				// dp[i][k]와 dp[k+1][j]로 현재 길이를 k 기준으로 2개로 나누어 이미 계산된 최소값들을 더한다
				// 크기가 N * M인 행렬과 M * K인 행렬을 곱할 때 필요한 곱셈 연산의 수는 총 N * M * K번
				// 앞서 dp에서 가져온 두 행렬을 곱하는데 필요한 연산 수 계산해 더해준다 
			}
		}
	}

	printf("%d", dp[0][N - 1]);
	return 0;
}