#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;
	int t, tt;
	int i, j, k;
	int num[100] = { 0, };

	scanf("%d %d", &n, &m);

	for (t = 0; t < m; t++)	// m번 공을 넣음
	{
		scanf("%d %d %d", &i, &j, &k);
		for (tt = i - 1; tt < j; tt++)
		{
			num[tt] = k;
		}
	}

	for (t = 0; t < n; t++)	// n개의 바구니를 출력함
	{
		printf("%d ", num[t]);
	}

	return 0;
}