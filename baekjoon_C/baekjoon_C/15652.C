#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int arr[8] = { 0, };

void dfs(int depth, int num)
{
	int i;
	if (depth == m)	// 깊이가 m이면 현재까지 저장했던 수열을 출력
	{
		for (i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = num; i <= n; i++)
		{
			arr[depth] = i;	// 현재 깊이의 숫자는 i로 저장
			dfs(depth + 1, i);	// 다음 깊이로 넘어간다 / 다음 깊이에서 시작 숫자는 i가 된다
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0, 1);	// 깊이 0부터 시작, 숫자는 1부터 시작

	return 0;
}