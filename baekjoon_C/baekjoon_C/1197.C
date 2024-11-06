#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int V, E;
int tree[10001][10001];	
int visit[10001] = { 0, };
int result = 0;

int prim(int start)
{
	int min, temp, i, j;

	visit[start] = 1;

	while (1)
	{
		min = 1000001;
		temp = 0;

		for (i = 1; i <= V; i++)
		{
			if (visit[i]==1)	// 방문한 정점이라면
			{
				for (j = 1; j <= V; j++)
				{
					if (visit[j] == 0 && min > tree[i][j])	// 방문한 정점과 연결된 정점 중 방문하지 않은 정점의 가중치가 min보다 작다면
					{
						min = tree[i][j];	// min에 가중치를 저장하고 temp에 정점을 저장함
						temp = j;
					}
				}
			}
		}
		
		if (temp == 0)	// 만약 방문한 정점들과 연결된 방문하지 않은 정점이 없다면 
		{
			break;	// 무한루프 탈출
		}

		visit[temp] = 1;// 가장 작은 가중치로 연결되어 있는 정점을 방문
		result += min;	// 가장 작은 가중치를 result에 더해줌
	}
	
	return 0;
}

int main()
{
	int i, j;
	int a, b, c;

	for (i = 0; i < 10001; i++)	// 초기화
	{
		for (j = 0; j < 10001; j++)
		{
			tree[i][j] = 1000001; // 초기값을 가장 큰 값으로 설정
		}
	}

	scanf("%d %d", &V, &E);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		tree[a][b] = c;
		tree[b][a] = c;
	}


	prim(1);

	printf("%d", result);

	return 0;
}