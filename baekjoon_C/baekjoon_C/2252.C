#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

///// 인접 리스트 구조체 //////
typedef struct 
{
	int value;	// 노드번호
	struct connGraph* next; // 다음 리스트 주소
}connGraph;

////// 인접리스트와 진입차수 배열 선언///////
connGraph* graph[MAX + 1] = { NULL };
int inDegree[MAX + 1] = {0,};

void addEdge(int front, int rear)	// 리스트 추가
{
	connGraph* newNode = (connGraph*)malloc(sizeof(connGraph));
	newNode->value = rear;
	newNode->next = graph[front]; // 앞에서 저장했던 주소를 next에 저장해준다
	graph[front] = newNode;	//newNode의 주소를 저장해 둔다 (다음 값이 들어오면 그 값의 next에 저장된다)
}

int main()
{
	int N; // 학생 수 
	int M; // 키를 비교한 횟수 

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		addEdge(a,b);	// a -> b
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
		printf("%d ", node);
		connGraph* current = graph[node];	// 현재 graph에 저장된 주소를 가져온다(마지막으로 추가된 값)
		while (current != NULL)	// current가 NULL이 될 때 까지 반복
		{
			inDegree[current->value] -= 1;
			if (inDegree[current->value] == 0)	// 인접차수가 0이면 큐에 추가
			{
				enqueue(current->value);
			}
			current = current->next;	// 다음 연결 리스트로 이동
		}

	}

	//// 메모리 해제 ////
	for (int i = 1; i <= N; i++)
	{
		connGraph* current = graph[i];
		while (current != NULL)
		{
			connGraph* temp = current;	// current의 주소를 저장
			current = current->next;	// current를 다음 리스트 주소로 변경
			free(temp);					// 메모리 해제 
		}
	}

	return 0;
}