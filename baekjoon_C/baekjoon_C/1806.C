#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN(x,y) x<y?x:y

int num[100000];

int main()
{
	int N, S;
	int sum = 0;
	int result = 100000001;

	int start = 0;
	int end = 0;

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	while (end < N) {
		sum += num[end++]; // 끝 지점을 더해주고 끝 지점 이동

		while (sum >= S) // 합이 S 이상이면
		{ 
			result = MIN(result, (end - start));
			sum -= num[start++]; // 시작지점 이동(이동하면서 현재 시작지점 값을 빼줌)
		}
	}

	if (result == 100000001)
	{
		result = 0;
	}

	printf("%d", result);
}