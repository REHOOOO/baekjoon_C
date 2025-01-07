#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000000

///// LIS 문제 /////

int A[MAX];
int dp[MAX];
int index[MAX];	// LIS 자리를 저장 
int result[MAX];

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
		index[i] = pos;	// index에 현재 순서를 저장

		if (pos == len)	// 만약 가장 큰 값이 들어왔으면 dp 크기를 늘려준다
		{
			len++;
		}
	}


	int temp = N - 1;	// 배열의 끝에서부터 시작
	int i = len - 1;  // LIS의 길이를 기준으로 시작
	
	while (i >= 0)
	{
		if (index[temp] == i)	// 만약 index[temp]가 i와 같다면 (시작은 가장 큰 번호)
		{
			result[i] = A[temp];	// i순서의 숫자를 불러와 result i순서에 저장
			i--;	// i를 하나 낮추어 찾는다 
		}
		temp--;
	}

	////// 결과 출력 //////
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", result[i]);
	}

}