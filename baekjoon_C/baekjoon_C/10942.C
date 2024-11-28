#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[2001];
int dp[2001][2001];
int S[1000000];
int E[1000000];

int main()
{
	int N, M;
	int i;

	scanf("%d", &N);	// 수열의 크기
	
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);	// 수열 입력
	}

	scanf("%d", &M);	// 질문의 개수

	for (i = 0; i < M; i++)	// 질문 입력
	{
		scanf("%d", &S[i]);
		scanf("%d", &E[i]);
	}

	//// 팰린드롬 찾기 ////
	
	for (i = 1; i <= N; i++)
	{
		dp[i][i] = 1;	// 길이가 1일때
		if (i != N)
		{
			if (num[i] == num[i + 1])	// 길이가 2일때
			{
				dp[i][i + 1] = 1;
			}
		}
	}

	for (int len = 3; len <= N; len++)	// 길이가 3 이상 일때 
	{
		for (int start = 1; start <= N - len + 1; start++)	// 시작지점
		{
			int end = start + len - 1;	// 끝지점
			if (num[start] == num[end] && dp[start + 1][end - 1] == 1) // 3부터 차근차근 올라가기 때문에 이전값들이 팰린드롬인지만 확인하면 됨
			{
				dp[start][end] = 1; // 팰린드롬
			}
		}
	}

	//// 출력 ////
	for (i = 0; i < M; i++)
	{
		printf("%d\n", dp[S[i]][E[i]]);
	}
}