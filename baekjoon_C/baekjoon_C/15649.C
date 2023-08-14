#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int arr[8] = { 0, };
int visit[8] = { 0, };

void dfs(int depth)
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
		for (i = 1; i <= n; i++)
		{
			if (visit[i - 1] == 1)	// 이미 사용한 숫자이면 넘어간다
			{
				continue;
			}
			else
			{
				arr[depth] = i;	// 현재 깊이의 숫자는 i로 저장
				visit[i - 1] = 1;	// 사용했다는 정보를 저장
				dfs(depth + 1);	// 다음 깊이로 넘어간다
				visit[i - 1] = 0;	// 다음 깊이에서 작업이 끝나면 초기화 시켜준다
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0);	// 깊이 0부터 시작

	return 0;
}

// 참고 https://giantbaby1012.tistory.com/117