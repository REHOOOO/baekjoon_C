#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int vertex;		// 연결된 정점 번호
	int weight;		// 해당 간선의 가중치
	struct Node* next;	// 다음 노드를 가리키는 포인터
} Node;

int V, E;
Node* adjList[10001] = { NULL };	// 인접 리스트
int visit[10001] = { 0, };
int result = 0;

void addEdge(int u, int v, int w)
{
	// 정점 u에 연결된 정점 v와 가중치 w 추가
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = v;
	newNode->weight = w;
	newNode->next = adjList[u];
	adjList[u] = newNode;

	// 정점 v에 연결된 정점 u와 가중치 w 추가
	newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = u;
	newNode->weight = w;
	newNode->next = adjList[v];
	adjList[v] = newNode;
}

int prim(int start)
{
	int min, temp, i;

	visit[start] = 1;

	while (1)
	{
		min = 1000001;
		temp = 0;

		for (i = 1; i <= V; i++)
		{
			if (visit[i]==1)	// 방문한 정점이라면
			{
				Node* node = adjList[i];
				while (node != NULL) 
				{
					// 방문한 정점과 연결된 정점 중 방문하지 않은 정점의 가중치가 min보다 작다면
					if (visit[node->vertex] == 0 && min > node->weight)
					{
						// min에 가중치를 저장하고 temp에 정점을 저장함
						min = node->weight;
						temp = node->vertex;
					}
					node = node->next;
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
	int i, a, b, c;

	scanf("%d %d", &V, &E);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		addEdge(a, b, c);
	}


	prim(1);

	printf("%d", result);

	// 메모리 해제
	for (i = 1; i <= V; i++)
	{
		Node* node = adjList[i];
		while (node != NULL)
		{
			Node* temp = node;
			node = node->next;
			free(temp);
		}
	}

	return 0;
}