#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i, j;
	int r[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &r[i]);
	}

	for (i = 1; i < n; i++)
	{
		for (j = r[0]; j > 0; j--)
		{
			if (r[0] % j == 0 && r[i] % j == 0)
			{
				printf("%d/%d\n", r[0] / j, r[i] / j);
				break;
			}
		}
	}

	return 0;
}