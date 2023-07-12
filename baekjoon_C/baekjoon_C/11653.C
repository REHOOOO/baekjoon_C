#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i;
	int flag;

	scanf("%d", &n);

	if (n == 1)
	{
		return 0;
	}

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			n = n / i;
			printf("%d\n", i);
			i = 1;
		}
	}

	if (i == n)
	{
		printf("%d", i);
	}

	return 0;
}