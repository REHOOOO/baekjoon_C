#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int vertex;		// 연결된 정점 번호
	int weight;		// 해당 간선의 가중치
	struct Node* next;	// 다음 노드를 가리키는 포인터
} Node;

typedef struct {
	int vertex;	// 연결된 정점 번호
	int weight; // 해당 간선의 가중치
} HeapNode;

int V, E;
Node* adjList[10001] = { NULL };	// 인접 리스트
int visit[10001] = { 0, };
int result = 0;

// 최소 힙
HeapNode minHeap[100001];
int heapsize = 0;	// 현재 힙에 저장된 간선의 개수

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

// swap 함수
void swap(HeapNode* a, HeapNode* b)
{
	HeapNode temp = *a;
	*a = *b;
	*b = temp;
}

void push(int vertex, int weight) // 최소 힙에 간선 추가
{
	minHeap[heapsize].vertex = vertex;	// minHeap의 마지막 위치에 새로운 HeapNode를 추가
	minHeap[heapsize].weight = weight;
	int current = heapsize++;	// heapsize를 1 올려준다

	// current가 0보다 크고 현재 가중치가 부모 노드의 가중치보다 작을 때 
	// 부모 노드 위치는 (current - 1) / 2
	while (current > 0 && minHeap[current].weight < minHeap[(current - 1) / 2].weight) 
	{
		swap(&minHeap[current], &minHeap[(current - 1) / 2]);	// 부모 노드와 swap 
		current = (current - 1) / 2;	// current를 부모 노드로 조정
	}
}

HeapNode pop()	// 최소 가중치 간선을 제거하고 반환
{
	HeapNode root = minHeap[0];	// 최소 가중치 간선은 minHeap[0]에 저장되어 있음
	minHeap[0] = minHeap[--heapsize];	// 마지막 간선을 minHeap[0]에 저장하고 heapsize를 1 감소
	int current = 0;
	while (1)
	{
		int left = current * 2 + 1;	// 왼쪽 자식 위치
		int right = current * 2 + 2;	// 오른쪽 자식 위치
		int smallest = current;	
		if (left < heapsize && minHeap[left].weight < minHeap[smallest].weight)	// 왼쪽 자식이 부모보다 작을 경우
			smallest = left;
		if (right < heapsize && minHeap[right].weight < minHeap[smallest].weight)	// 오른쪽 자식이 smallest보다 작을 경우
			smallest = right;
		if (smallest == current)	// 부모가 가장 작을 경우
			break;
		swap(&minHeap[current], &minHeap[smallest]);	// 부모와 자식을 swap한다
		current = smallest;	// 자식 중 가중치가 작았던 쪽으로 이동
	}
	return root;
}

int prim(int start)
{
	push(start, 0);	// 시작 정점을 힙에 push

	while (heapsize > 0)	// 힙에 간선이 남아있는 동안 반복
	{
		HeapNode minNode = pop();	// 최소 가중치 간선을 꺼냄
		int u = minNode.vertex;
		int weight = minNode.weight;

		if (visit[u])	// 이미 방문된 정점이라면 넘어감
			continue;

		visit[u] = 1;	// 방문 표시
		result += weight;	// result에 가중치를 추가

		Node* node = adjList[u];	// u에 연결된 연결 정보를 가져온다
		while (node != NULL) 
		{
			if (!visit[node->vertex])	// 연결 된 정점 중 방문하지 않은 정점
				push(node->vertex, node->weight);	// 정보를 힙에 추가해준다
			node = node->next;	// 다음 연결 정보로 넘어감
		}
	}
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