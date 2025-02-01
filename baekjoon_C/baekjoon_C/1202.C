#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int M;	// 보석 무게
	int V;	// 보석 가격
} data;

int compare_bag(const void* a, const void* b) //오름차순으로 정렬 
{ 
	return (*(int*)a - *(int*)b);
}

int compare_jewel(const void* a, const void* b) // 보석 무게 기준 오름차순으로 정렬
{
	return (((data*)a)->M - ((data*)b)->M);
}

///// 우선순위 큐 /////
int heap[300000];
int heap_size = 0;

void push(int value) 
{
	heap[++heap_size] = value;
	int current = heap_size;

	while (current > 1 && heap[current] > heap[current / 2]) 
	{
		int temp = heap[current];
		heap[current] = heap[current / 2];
		heap[current / 2] = temp;
		current /= 2;
	}
}

int pop() 
{
	if (heap_size == 0) return 0;

	int result = heap[1];
	heap[1] = heap[heap_size--];
	int current = 1;

	while (current * 2 <= heap_size) 
	{
		int child = current * 2;
		if (child < heap_size && heap[child] < heap[child + 1]) 
		{
			child++;
		}
		if (heap[current] >= heap[child])
		{
			break;
		}
		int temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;
		current = child;
	}

	return result;
}
/////////////////////////////////

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
	qsort(jewel, N, sizeof(data), compare_jewel);	// 보석을 무게 오름차순으로 정렬

	long long int result = 0;	// 결과 계산
	int j = 0;		// 보석 번호

	for (int i = 0; i < K; i++)	// i는 가방 번호
	{
		while (j < N && jewel[j].M <= C[i])	// 아직 큐에 안들어간 보석이 있고 현재 보석이 가방무게보다 가볍거나 같다면
		{
			push(jewel[j].V);	// 보석의 가격을 우선순위 큐에 넣어준다 (비싼 보석이 우선순위를 가진다)
			j++;	// 보석 번호를 변경
		}

		result += pop();	// 가장 가치가 높은 보석의 가격을 더해준다 (큐가 비어있을 경우 0)
	}


	printf("%lld", result);
}