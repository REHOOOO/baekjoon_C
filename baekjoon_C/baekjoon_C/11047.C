#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int k;
	int a[10];
	int i;
	int cnt = 0;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = n - 1; i >= 0; i--)
	{
		if (k / a[i] >= 1)
		{
			cnt = cnt + (k / a[i]);
			k = k % a[i];
		}
	}

	printf("%d", cnt);

	return 0;
}