#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int a, b, v;
	int cnt = 0;
	int h = 0;

	scanf("%d %d %d", &a, &b, &v);

	while (1)
	{
		cnt = cnt + 1;

		h = h + a;
		if (h >= v)
		{
			break;
		}

		h = h - b;
	}

	printf("%d", cnt);

	return 0;
}