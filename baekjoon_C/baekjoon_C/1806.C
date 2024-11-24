#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[10000];

int main()
{
	int N, S;
	int sum = 0;
	int result = 100000001;

	int start = 0;
	int end = 0;

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	while (end <= N)
	{
		if (sum >= S) // 현재 부분합이 S 이상이면 
		{
			if (result > (end - start)) // result보다 현재 선택된 수의 개수가 작다면
			{
				result = end - start;	// result에 현재 개수 저장
			}
			sum -= num[start++]; // 시작지점을 이동 (이동하기 전에 시작지점 값을 빼준다)
		}
		else // 현재 부분합이 S가 안된다면
		{
			if (end < N) // 끝 지점이 N보다 작다면 
			{
				sum += num[end++]; // sum에 끝지점을 더해주고 끝지점을 이동시켜준다
			}
			else
			{
				break;
			}
		}

		if (result == 1)	// 만약 sum이 1이라면 (최소값)
		{
			break;
		}
	}

	if (result == 100000001)
	{
		result = 0;
	}

	printf("%d", result);
}