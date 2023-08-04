#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

////// 전역변수 ///////
int chk;
int num;

///////////////// 큐 설정 //////////////////
typedef struct Node	// 노드 정의
{
	int data;
	int check;
	struct Node *next;
}Node;

typedef struct Queue	// 큐 정의
{
	Node *front;
	Node *rear;
	int count;	// 큐 내부에 노드 개수
}Queue;

void initQueue(Queue *queue) // 큐 초기화
{
	queue->front = queue->rear = NULL;	// 큐 초기화
	queue->count = 0; // 큐 내부의 노드 개수를 초기화
}

int isEmpty(Queue *queue)	// 큐가 비었는지 확인
{
	return queue->count == 0;	// 큐 내부의 노드 개수가 0일 경우
}

void enqueue(Queue* queue, int data, int check)	// 노드 추가
{
	Node *newNode = (Node *)malloc(sizeof(Node)); // newNode 생성
	newNode->data = data;
	newNode->check = check;
	newNode->next = NULL;

	if (isEmpty(queue))	// 큐가 비어있을 때 
	{
		queue->front = newNode;
	}
	else // 비어있지 않을 때
	{
		queue->rear->next = newNode; // 맨 뒤 노드의 다음을 newNode로 설정
	}
	queue->rear = newNode;	// 큐의 맨 뒤를 newNode로 설정
	queue->count++; // 큐 내부의 노드 개수를 1 증가
}

void dequeue(Queue* queue)
{
	Node* ptr;
	if (isEmpty(queue))	// 큐가 비었을 때
	{
		return 0;
	}
	ptr = queue->front;	// 맨 앞 노드가져온다
	num = ptr->data;	// 전역변수에 데이터 저장 
	chk = ptr->check;
	queue->front = ptr->next;	// 큐의 맨 앞을 ptr의 다음 노드로 설정
	free(ptr);	// ptr노드 해제 
	queue->count--;	// 큐 내부의 노드 개수를 1 감소
}

int main()
{
	int t, n, m;
	int i, j, k;
	int priority;
	int cnt = 0;
	Queue queue;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		cnt = 0;
		initQueue(&queue);	// 큐 초기화

		scanf("%d %d", &n, &m);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &priority);	// 중요도를 입력받는다
			if (j == m)
			{
				enqueue(&queue, priority, 1);	// m번째 노드는 check가 1
			}
			else
			{
				enqueue(&queue, priority, 0);
			}
		}


		for (j = 9; j >= 1; j--)
		{
			for (k = 0; k < queue.count; k++)
			{
				dequeue(&queue);
				if (num == j)
				{
					if (chk == 1)
					{
						cnt = cnt + 1;
						break;
					}
					else
					{
						cnt = cnt + 1;
					}
				}
				else
				{
					cnt = cnt + 1;
					enqueue(&queue, num, chk);
				}
			}
			if (chk == 1)
			{
				break;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}