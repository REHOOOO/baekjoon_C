#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[2001];
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
	int start, end;
	int flag;

	for (i = 0; i < M; i++)
	{
		start = S[i];
		end = E[i];
		flag = 1;
		while (start < end)
		{
			if (num[start] == num[end])	// 숫자가 같다면 
			{
				start++;
				end--;
			}
			else	// 숫자가 다르다면
			{
				flag = 0;
				break;
			}
		}
		
		if (flag == 0)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
}