#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n, i, v;
	int cnt = 0;


	scanf("%d", &n);
	int num[100];
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	scanf("%d", &v);

	for (i = 0; i < n; i++)
	{
		if (num[i] == v)
		{
			cnt = cnt + 1;
		}
	}

	printf("%d", cnt);

	return 0;
}