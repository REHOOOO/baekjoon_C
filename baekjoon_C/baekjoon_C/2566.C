#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[9][9];
	int i, j;
	int max = -1;
	int row, column;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &a[i][j]);

			if (max < a[i][j])
			{
				max = a[i][j];

				row = i + 1;
				column = j + 1;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", row, column);

	return 0;
}