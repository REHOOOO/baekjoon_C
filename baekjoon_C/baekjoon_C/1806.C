#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[10000];

int main()
{
	int N, S;
	int i, j;
	int sum, result;

	scanf("%d %d", &N, &S);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	result = 100000001;
	for (i = 0; i < N; i++)
	{
		sum = num[i];
		for (j = i + 1; j < N; j++)
		{
			sum = sum + num[j];	// sum에 num[j]를 더해준다
			if (sum > S)	// 만약 sum이 S보다 커진다면
			{
				if (result > (j - i + 1))	// result보다 선택된 수의 개수가 작다면 result에 sum을 저장
				{
					result = (j - i + 1);
				}
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