#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int maze[100][100] = { 0, };
int result = 10000;

int search(int y, int x, int cnt)
{
	if (result == n + m - 1)	// 이미 최소값을 찾은 경우 
	{
		return 0;
	}

	if (result < cnt)	// 현재 최소값보다 cnt가 커질 경우
	{
		return 0;
	}

	if ((y == n - 1) && (x == m - 1))	// 마지막에 도달했을 경우
	{
		if (result > cnt)
		{
			result = cnt;
		}
	}

	if ((y + 1 < n) && (maze[y + 1][x] == 1))	// 아래가 1일 경우
	{
		maze[y][x] = 0;
		search(y + 1, x, cnt + 1);
		maze[y][x] = 1;
	}

	if ((x + 1 < m) && (maze[y][x + 1] == 1))	// 오른쪽이 1일 경우
	{
		maze[y][x] = 0;
		search(y, x + 1, cnt + 1);
		maze[y][x] = 1;
	}

	if ((y - 1 >= 0) && (maze[y - 1][x] == 1))	// 위가 1일 경우
	{
		maze[y][x] = 0;
		search(y - 1, x, cnt + 1);
		maze[y][x] = 1;
	}

	if ((x - 1 >= 0) && (maze[y][x - 1] == 1))	// 왼쪽이 1일 경우
	{
		maze[y][x] = 0;
		search(y, x - 1, cnt + 1);
		maze[y][x] = 1;
	}

	return 0;
}

int main()
{
	int i, j;
	char num[100];
	int cnt = 0;


	// 미로 정보 입력
	scanf("%d %d", &n, &m);

	// 미로 입력
	for (i = 0; i < n; i++)
	{
		scanf("%s", &num);
		for (j = 0; j < m; j++)
		{
			if (num[j] == '1')
			{
				maze[i][j] = 1;
			}
		}
	}

	search(0, 0, 1);
	printf("%d", result);

	return 0;
}