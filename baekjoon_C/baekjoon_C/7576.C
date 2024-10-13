#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int box[1000][1000] = { 0, };
int queue[1000000][2] = { 0, };

int BFS()
{
	int i, j;
	int front = 0;
	int rear = 0;
	int max = 0;

	// 초기 토마토 위치 찾기
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (box[i][j]==1)
			{
				queue[rear][0] = j;
				queue[rear][1] = i;
				rear++;
			}
		}
	}

	while (front < rear)
	{
		int x = queue[front][0];
		int y = queue[front][1];
		front++;

		if ((y + 1 < n) && (box[y + 1][x] == 0))	// 아래가 0일 경우
		{
			box[y + 1][x] = box[y][x] + 1;
			queue[rear][0] = x;
			queue[rear][1] = y + 1;
			rear++;
		}

		if ((x + 1 < m) && (box[y][x + 1] == 0))	// 오른쪽이 0일 경우
		{
			box[y][x + 1] = box[y][x] + 1;
			queue[rear][0] = x + 1;
			queue[rear][1] = y;
			rear++;
		}

		if ((y - 1 >= 0) && (box[y - 1][x] == 0))	// 위가 0일 경우
		{
			box[y - 1][x] = box[y][x] + 1;
			queue[rear][0] = x;
			queue[rear][1] = y - 1;
			rear++;
		}

		if ((x - 1 >= 0) && (box[y][x - 1] == 0))	// 왼쪽이 0일 경우
		{
			box[y][x - 1] = box[y][x] + 1;
			queue[rear][0] = x - 1;
			queue[rear][1] = y;
			rear++;
		}
	}

	// 토마토의 상태 확인
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (box[i][j] == 0)	// 익지 못한 토마토가 있을 시 
			{
				printf("%d", -1);
				return 0;
			}
			else if (max < box[i][j])
			{
				max = box[i][j];
			}
		}
	}

	printf("%d", max-1);

	return 0;
}


int main()
{
	int i, j;
	
	scanf("%d %d", &m, &n);

	// 입력
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
		}
	}

	BFS();

	return 0;
}