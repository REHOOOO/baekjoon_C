#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int x = 0;
	int n = 0;
	int i = 0;
	int cnt = 0;
	int a, b;

	scanf("%d", &x);
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		cnt = cnt + (a * b);
	}

	if (cnt == x)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}

	return 0;
}