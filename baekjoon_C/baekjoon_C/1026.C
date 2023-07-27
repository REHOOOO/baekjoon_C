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

int desc(const void* a, const void* b)
{
	int num1 = *(int*)a; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b; // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 > num2)
	{
		return -1;
	}

	if (num1 < num2)
	{
		return 1;
	}

	return 0;
}

int S(int a[], int b[], int n)
{
	int i;
	int total = 0;

	for (i = 0; i < n; i++)
	{
		total = total + (a[i] * b[i]);
	}

	return total;
}

int main()
{
	int n;
	int i;
	int a[50];
	int b[50];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}

	qsort(a, n, sizeof(int), asc);
	qsort(b, n, sizeof(int), desc);

	printf("%d", S(a, b, n));

	return 0;
}