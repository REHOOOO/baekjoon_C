#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int M;	// 보석 무게
	int V;	// 보석 가격
} data;

int compare_bag(const void* a, const void* b) { //오름차순으로 정렬 
	return (*(int*)a - *(int*)b);
}

int compare_jewel(const void* a, const void* b) { // 보석 가격 기준 내림차순으로 정렬
	return (((data*)b)->V - ((data*)a)->V);
}

data jewel[300000];
int C[300000];	// 가방 최대 무게

int main()
{
	int N, K;	// 보석 개수, 가방 개수
	

	///// 입력 /////
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &jewel[i].M, &jewel[i].V);
	}
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &C[i]);
	}

	qsort(C, K, sizeof(int), compare_bag);	// 가방을 오름차순으로 정렬
	qsort(jewel, N, sizeof(data), compare_jewel);	// 보석을 가격 내림차순으로 정렬

	int result = 0;	// 결과 계산
	int available = K;
	for (int i = 0; i < N; i++)	// 보석 번호
	{
		for (int j = 0; j < K; j++)	// 가방 번호
		{
			if (C[j] > 0)	// 가방이 사용 가능하다면
			{
				if (C[j] > jewel[i].M)
				{
					result += jewel[i].V;	// 보석 가격 계산
					C[j] = -1;	// 가방 사용 표시
					available--;	// 남은 가방 수 
					break;
				}
			}
		}
		if (available < 1)	// 남은 가방이 없으면 루프 종료
		{
			break;
		}
	}

	printf("%d", result);
}