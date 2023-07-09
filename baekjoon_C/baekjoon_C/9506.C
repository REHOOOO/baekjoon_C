#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i;
	int cnt = 0;

	while (1)
	{
		scanf("%d", &n);
		if (n == -1)
		{
			break;
		}

		cnt = 0;
		for (i = 1; i < n; i++)	// 약수 찾아서 더하기 (완전수인지 확인)
		{
			if (n % i == 0)
			{
				cnt = cnt + i;
			}
		}
		
		if (cnt == n)	// 완전수라면 약수들 출력
		{
			printf("%d = 1", n);
			for (i = 2; i < n; i++)
			{
				if (n % i == 0)
				{
					printf(" + %d", i);
				}
			}
			printf("\n");
		}
		else // 완전수가 아니라면 
		{
			printf("%d is NOT perfect.\n", n);
		}
	}

	return 0;
}