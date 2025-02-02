#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int A[4000];
int B[4000];
int C[4000];
int D[4000];

int main()
{
	int n;	// 배열의 크기
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}


}