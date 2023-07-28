#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort 함수

int asc(const void* a, const void* b)
{
	int num1 = *(int*)a; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)
	{
		return -1;
	}

	if (num1 > num2)
	{
		return 1;
	}

	return 0;
}

int main()
{
	int n;
	int pi[1000];
	int i, j;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &pi[i]);
	}

	qsort(pi, n, sizeof(int), asc);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			cnt = cnt + pi[j];
		}
	}
	
	printf("%d", cnt);

	return 0;
}