#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int memory[100];
int cost[100];

int main()
{
	int N, M;	// 앱의 개수, 확보해야 하는 메모리 

	///// 입력 /////
	scanf("%d %d", &N, &M);
	for (int i=0; i < N; i++)
	{
		scanf("%d", &memory[i]);
	}
	for (int i=0; i < N; i++)
	{
		scanf("%d", &cost[i]);
	}

}