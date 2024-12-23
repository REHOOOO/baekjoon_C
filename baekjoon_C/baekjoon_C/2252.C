#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 32000

////// 위상정렬 사용 ///////

///////// 큐 /////////////
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x)
{
	queue[rear++] = x;
}

int dequeue()
{
	return queue[front++];
}

int isQueueEmpty()
{
	if (front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


////// 인접리스트와 진입차수 배열 ///////
int graph[MAX + 1][MAX + 1] = { 0, };
int inDegree[MAX + 1] = {0,};

int main()
{
	int N; // 학생 수 
	int M; // 키를 비교한 횟수 

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a][b] = 1;	// a->b
		inDegree[b] += 1;	// 인접차수 +1
	}

	for (int i = 1; i <= N; i++)	// 인접차수가 0이면 큐에 추가
	{
		if (inDegree[i] == 0)
		{
			enqueue(i);
		}
	}

	while (isQueueEmpty() != 1)
	{
		int node = dequeue();	// 큐에서 꺼낸다
		printf("%d", node);
		for (int i = 1; i <= N; i++)
		{
			if (graph[node][i] == 1)	// 현재 노드와 연결된 노드가 있으면 
			{
				inDegree[i] -= 1;	// 인접차수 -1
				if (inDegree[i] == 0)	// 그중 인접차수가 0이된 노드들을 큐에 추가
				{
					enqueue(i);
				}
			}
			
		}

	}

	return 0;
}