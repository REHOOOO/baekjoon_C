#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i;
	char str[20000][55];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}



	return 0;
}