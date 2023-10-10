#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int base, int exp)	// 제곱
{
	int i;
	int num = 1;
	for (i = 0; i < exp; i++)
	{
		num = num * base;
	}

	return num;
}

int main()
{
	int n, m;
	int i, j;
	int num, temp;
	int maze[100][100] = { 0, };

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);

		for (j = m; j > 0; j--)
		{
			temp = power(10, j - 1);

			if ((num / temp) % 2 == 1)	// num을 temp로 나누었을 때 홀수인 경우
			{
				maze[m - j][i] = 1;
			}
		}
	}

	return 0;
}