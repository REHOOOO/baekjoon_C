#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i;
	int n, k;
	int cnt = 0;
	int flag = 0;

	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cnt = cnt + 1;
			if (cnt == k)
			{
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1)
	{
		printf("%d", i);
	}
	else
	{
		printf("0");
	}

	return 0;
}