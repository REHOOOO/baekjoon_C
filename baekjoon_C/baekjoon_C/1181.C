#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // qsort
#include <string.h> // strcmp

int compare(const void* a, const void* b)
{
	return(strcmp((char*)a, (char*)b));
}

char str[20000][55];

int main()
{
	int n;
	int i;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}

	qsort((void*)str, n, sizeof(char*), compare);

	for (i = 0; i < n; i++)
	{
		printf("%s\n", str[i]);
	}

	return 0;
}