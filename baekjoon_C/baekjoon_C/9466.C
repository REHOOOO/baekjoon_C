#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int pick[100000];
int check[100000];
int cnt;

void dfs(int start, int node)
{
	if (check[node] == 1 || check[node] == 2)	// 이미 확인된 그룹일 경우 
	{
		return;
	}

	if (pick[node] == start)	// 시작 노드와 다음 노드가 같다면 
	{
		check[node] = 1;	// 확인 표시
		cnt--;	// 카운트를 줄여준다 

		return;
	}

	if (node == pick[node])	// 현재 노드가 자신을 가르킬 경우 
	{
		check[node] = 2;	// 확인 표시
		cnt--;	// 카운트를 줄여준다 
		return;
	}

	dfs(start, pick[node]);	// 다음 연결 노드로 이동 

	if (check[pick[node]] == 1)	// 다음 노드에서 확인표시가 생겼으면 
	{
		check[node] = 1;	// 확인 표시
		cnt--;
		return;
	}



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

		scanf("%d", &n);
		cnt = n;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &pick[j]);
			pick[j]--;
		}

		for (int j = 0; j < n; j++)
		{
			dfs(j, j);

		}

		printf("%d\n", cnt);

	}

	return 0;
}