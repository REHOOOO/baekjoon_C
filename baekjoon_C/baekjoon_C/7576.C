#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int box[1000][1000] = { 0, };

int main()
{
	int n, m;
	int i, j;
	

	scanf("%d %d", &m, &n);

	// 미로 입력
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
		}
	}

	return 0;
}