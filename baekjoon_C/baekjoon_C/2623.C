#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 1000

/////////// 큐 /////////////
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

///// 인접리스트, 진입차수 /////
int graph[MAX+1][MAX+1] = { 0, };
int inDegree[MAX+1] = { 0, };
int result[MAX];

int main()
{
	int N, M; // 가수 수, 보조 PD 수
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int num;
		int front = 0;
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			int x;
			scanf("%d", &x);
			if (front != 0)	// front가 초기값이 아니면 
			{
				if (graph[front][x] != 1)	// 중복 간선이 나올 수 있으므로 이미 생성된 간선이 있으면 생성하지 않는다
				{
					graph[front][x] = 1;
					inDegree[x] += 1;
				}
			}
			front = x;	// front를 현재 j로 교체
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)	// 진입차수가 0인 노드를 큐에 넣어준다
		{
			enqueue(i);
		}
	}

	int cnt = 0;
	while (isQueueEmpty() != 1)
	{
		int node = dequeue();
		result[cnt] = node;
		cnt++;
		for (int i = 1; i <= N; i++)
		{
			if (graph[node][i] == 1)	// 현재 노드와 연결된 노드들의 진입차수를 하나 줄인다
			{
				inDegree[i] -= 1;
				if (inDegree[i] == 0)	// 진입차수가 0이 된다면 큐에 넣어준다
				{
					enqueue(i);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] > 0)	// 만약 진입차수가 남아있는 노드가 있다면 
		{
			printf("0\n");	// 0을 출력하고 프로그램을 종료한다
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}