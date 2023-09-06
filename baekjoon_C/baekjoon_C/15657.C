#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort 함수

int n, m;
int arr[8] = { 0, };
int visit[8] = { 0, };
int num[8] = { 0, };

int asc(const void* a, const void* b)
{
	int num1 = *(int*)a; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)
	{
		return -1;
	}

	if (num1 > num2)
	{
		return 1;
	}

	return 0;
}

void dfs(int depth, int start)
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
		for (i = start; i < n; i++)
		{
			arr[depth] = num[i];	// 현재 깊이의 숫자는 i로 저장
			dfs(depth + 1, i);	// 다음 깊이로 넘어간다 / 시작 숫자를 정해준다
		}
	}
}

int main()
{
	int i;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), asc);
	dfs(0, 0);	// 깊이 0부터 시작

	return 0;
}