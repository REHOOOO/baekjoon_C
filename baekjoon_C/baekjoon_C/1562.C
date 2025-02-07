#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MOD 1000000000

int dp[101][10][1024];	// dp[길이][마지막 숫자][등장 숫자 체크 (1023 = 1111111111)]

int main()
{
	int N;
	scanf("%d", &N);

	memset(dp, 0, sizeof(dp));	// dp를 0으로 초기화

	// 초기값 설정 (1자리 수 일때)
	for (int i = 1; i < 10; i++)
	{
		dp[1][i][1 << i] = 1;
	}

	// dp 테이블 채우기
	for (int i = 2; i <= N; i++)	// 길이
	{
		for (int j = 0; j < 10; j++)	// 마지막 숫자
		{
			for (int mask = 0; mask < 1024; mask++)	// 등장 숫자 체크
			{
				if (j > 0)	// j가 0이 아닐 경우
				{
					// 이전 길이의 마지막 숫자가 1 작았던 숫자의 계단 수 개수를 더하고 MOD로 나눈 나머지를 저장한다
					dp[i][j][mask | (1 << j)] = (dp[i][j][mask | (1 << j)] + dp[i - 1][j - 1][mask]) % MOD;
				}
				if (j < 9)	// j가 9가 아닐 경우
				{
					// 이전 길이의 마지막 숫자가 1 컷던 숫자의 계단 수 개수를 더하고 MOD로 나눈 나머지를 저장한다
					dp[i][j][mask | (1 << j)] = (dp[i][j][mask | (1 << j)] + dp[i - 1][j + 1][mask]) % MOD;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result = (result + dp[N][i][1023]) % MOD;	// 1023 = 1111111111 이므로 0~9까지 모두 체크된 숫자들의 계단 수 개수를 더한 뒤 MOD로 나눈 나머지를 저장 
	}

	printf("%d", result);
	return 0;
}