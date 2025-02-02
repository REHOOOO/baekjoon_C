#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)	// 오름차순 정렬
{
	return (*(int*)a - *(int*)b);
}

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

	int* sumAB = (int*)malloc(n * n * sizeof(int));		// AB를 더한 모든 값들을 저장
	int* sumCD = (int*)malloc(n * n * sizeof(int));		// CD를 더한 모든 값들을 저장
	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sumAB[idx] = A[i] + B[j];	// AB를 더한 값들을 넣어준다
			sumCD[idx] = C[i] + D[j];	// CD를 더한 값들을 넣어준다
			idx++;
		}
	}

	qsort(sumAB, n * n, sizeof(int), compare);	// 오름차순으로 정렬
	qsort(sumCD, n * n, sizeof(int), compare);	// 오름차순으로 정렬

	int count = 0;
	int i = 0;
	int j = n * n - 1;

	///// 투포인터 /////
	while (i < n * n && j >= 0)
	{
		int sum = sumAB[i] + sumCD[j];
		if (sum == 0)	// sum이 0이면
		{
			int countAB = 1;
			int countCD = 1;
			while (i + 1 < n * n && sumAB[i] == sumAB[i + 1])	// sumAB에서 중복되는 값을 카운트 해준다
			{
				i++;
				countAB++;
			}
			while (j - 1 >= 0 && sumCD[j] == sumCD[j - 1])	// sumCD에서 중복되는 값을 카운트 해준다
			{
				j--;
				countCD++;
			}
			count += countAB * countCD;	// 더 이상 다음 값이 같지 않다면 각각의 중복된 값 개수를 곱해 count에 추가해준다
			i++;
			j--;
		}
		else if (sum < 0)	// sum이 0보다 작으면
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	free(sumAB);
	free(sumCD);

	printf("%d", count);
}