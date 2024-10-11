#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int maze[100][100] = { 0, };
int queue[10000][2] = { 0, };

int BFS()
{
	int front = 0;
	int rear = 1;

	while (front < rear)
	{
		int x = queue[front][0];
		int y = queue[front][1];
		front++;

		if (x == m - 1 && y == n - 1)
		{
			break;
		}

		if ((y + 1 < n) && (maze[y + 1][x] == 1))	// 아래가 1일 경우
		{
			maze[y + 1][x] = maze[y][x] + 1;
			queue[rear][0] = x;
			queue[rear][1] = y + 1;
			rear++;
		}

		if ((x + 1 < m) && (maze[y][x + 1] == 1))	// 오른쪽이 1일 경우
		{
			maze[y][x + 1] = maze[y][x] + 1;
			queue[rear][0] = x + 1;
			queue[rear][1] = y;
			rear++;
		}

		if ((y - 1 >= 0) && (maze[y - 1][x] == 1))	// 위가 1일 경우
		{
			maze[y - 1][x] = maze[y][x] + 1;
			queue[rear][0] = x;
			queue[rear][1] = y - 1;
			rear++;
		}

		if ((x - 1 >= 0) && (maze[y][x - 1] == 1))	// 왼쪽이 1일 경우
		{
			maze[y][x - 1] = maze[y][x] + 1;
			queue[rear][0] = x - 1;
			queue[rear][1] = y;
			rear++;
		}
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

	BFS();
	printf("%d", maze[n - 1][m - 1]);

	return 0;
}