#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000000

///// LIS 문제 /////

int A[MAX];
int dp[MAX];
int prev[MAX];
int result[MAX];

int main()
{
	// 입력
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	///// 마지막이 A[i]가 되는 수열의 크기를 dp에 저장한다 /////
	int maxlen = 0;
	int maxIndex = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;	// 기본적으로 자기 자신만으로 1이 된다
		prev[i] = -1;	// 자신이 출발 점일 경우 -1을 저장해 둔다
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && dp[i] < dp[j] + 1)	// 앞 쪽의 숫자가 자신보다 작고 dp가 자신보다 크면 dp를 변경해준다
			{
				dp[i] = dp[j] + 1;	// 자신까지 포함되어 1 추가 된다 
				prev[i] = j;	// 이전 숫자 인덱스를 저장해 두어 역추적을 할 수 있도록 해준다
			}
		}
		if (dp[i] > maxlen)	// 현재까지의 최대값보다 크면 저장해준다
		{
			maxlen = dp[i];
			maxIndex = i;
		}
	}

	int temp = maxIndex;	// 처음 temp는 저장해둔 가장 큰 값의 인덱스 
	for (int i = maxlen-1; i >= 0; i--)	// 끝에서 부터 채워 넣는다 
	{
		result[i] = A[temp];	// temp 순서에 있는 숫자를 result에 저장
		temp = prev[temp];		// prev[temp]에 저장된 앞 숫자의 인덱스를 가져온다
	}

	printf("%d\n", maxlen);
	for (int i = 0; i < maxlen; i++)
	{
		printf("%d ", result[i]);
	}

}