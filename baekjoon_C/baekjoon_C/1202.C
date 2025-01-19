#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, K;	// 보석 개수, 가방 개수
	int M[300000];	// 보석 무게
	int V[300000];	// 보석 가격
	int C[300000];	// 가방 최대 무게

	///// 입력 /////
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &M[i], &V[i]);
	}
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &C[i]);
	}

}