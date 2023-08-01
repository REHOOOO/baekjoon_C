#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[100000];

int main()
{
	int k;
	int i;
	int total = 0;
	int cnt = 0;
	int n;
	
	scanf("%d", &k);

	for (i = 0; i < k; i++)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			cnt = cnt - 1;
			total = total - num[cnt];
		}
		else
		{
			num[cnt] = n;
			total = total + num[cnt];
			cnt = cnt + 1;
		}
	}

	printf("%d", total);

	return 0;
}