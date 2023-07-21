#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort 함수

int num[1000000];

int compare(const void* a, const void* b)
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
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	qsort(num, n, sizeof(int), compare);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}