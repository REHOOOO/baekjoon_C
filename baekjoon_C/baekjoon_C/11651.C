#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// qsort 함수

int xy[2][100000];

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
		scanf("%d %d", &xy[0][i], &xy[1][i]);
	}

	//qsort(xy[0], n, sizeof(int), compare);
	qsort(xy, n, sizeof(int), compare);


	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", xy[0][i], xy[1][i]);
	}

	return 0;
}