#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int pick[100000];
int check[100000];
int visit[100000];
int cnt;

void dfs(int node)
{
	visit[node] = 1;	// 방문 표시
	int next = pick[node];	// 다음 가르키는 노드를 저장

	if (visit[next] == 0)	// 다음 노드가 방문되지 않은 노드라면
	{
		dfs(next);	// 다음 노드로 이동
	}
	else if (check[next] == 0)	// 방문은 되었지만 확인이 안되어있다면 순환이 발생
	{
		while (check[node] == 0)	// 순환 내에 있는 노드들을 모두 확인 표시 해준다
		{
			check[node] = 1;	// 확인 표시
			node = pick[node];	// 다음 노드
			cnt--;	// 카운트 감소 
		}
		return;
	}

	check[node] = 1;	// 다음 노드가 방문되었고 확인도 되어있다면 순환에 들어가지 못함 (확인 표시)
	return;
}

int main()
{
	int T;
	int n;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		///// 초기화 /////
		cnt = 0;
		memset(check, 0, sizeof(check));
		memset(pick, 0, sizeof(pick));
		memset(visit, 0, sizeof(visit));

		scanf("%d", &n);
		cnt = n;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &pick[j]);
			pick[j]--;
		}

		for (int j = 0; j < n; j++)
		{
			dfs(j);

		}

		printf("%d\n", cnt);

	}

	return 0;
}