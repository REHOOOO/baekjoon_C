#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000000

///// LIS 문제 /////

int A[MAX];
int dp[MAX];

///// 이진 탐색 /////
int binarySearch(int* arr, int size, int target)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < target)	// 만약 타겟이 중간보다 크면 
		{
			left = mid + 1;	// left는 중간보다 +1
		}
		else
		{
			right = mid - 1; // 아니면 right를 중간보다 -1
		}
	}
	return left;
}

int main()
{
	// 입력
	int N;
	scanf("%d", &N);

	int len = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);

		int pos = binarySearch(dp, len, A[i]); // A[i]가 들어갈 위치를 찾는다 
		dp[pos] = A[i];	// dp에 A[i]를 넣어준다

		if (pos == len)	// 만약 가장 큰 값이 들어왔으면 dp 크기를 늘려준다
		{
			len++;
		}
	}

	////// 결과 출력 //////
	printf("%d\n", len);
}