#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i, j;
	int temp;
	int xy[100000][2];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &xy[i][0], &xy[i][1]);
	}

	for (i = 0; i < n; i++)	// 버블정렬
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (xy[j][1] > xy[j + 1][1])
			{
				temp = xy[j][1];
				xy[j][1] = xy[j + 1][1];
				xy[j + 1][1] = temp;

				temp = xy[j][0];
				xy[j][0] = xy[j + 1][0];
				xy[j + 1][0] = temp;
			}
			else if (xy[j][1] == xy[j + 1][1])
			{
				if (xy[j][0] > xy[j + 1][0])
				{
					temp = xy[j][1];
					xy[j][1] = xy[j + 1][1];
					xy[j + 1][1] = temp;

					temp = xy[j][0];
					xy[j][0] = xy[j + 1][0];
					xy[j + 1][0] = temp;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", xy[i][0], xy[i][1]);
	}

	return 0;
}