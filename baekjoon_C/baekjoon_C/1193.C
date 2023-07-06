#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int l = 1;
	int r = 1;
	int cnt = 1;
	int x;
	int flag = 1;

	scanf("%d", &x);

	while (x != 1)
	{
		if (flag == 0)
		{
			if (r == 1)
			{
				l = l + 1;
				flag = 1;
			}
			else
			{
				l = l + 1;
				r = r - 1;
			}
		}
		else if (flag == 1)
		{
			if (l == 1)
			{
				r = r + 1;
				flag = 0;
			}
			else
			{
				r = r + 1;
				l = l - 1;
			}
		}

		cnt = cnt + 1;
		if (cnt == x)
		{
			break;
		}
	}

	printf("%d/%d", l, r);

	return 0;
}