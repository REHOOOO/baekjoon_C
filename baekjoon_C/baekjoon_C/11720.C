#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i;
	char str[100];
	int num = 0;

	scanf("%d", &n);
	scanf("%s", str);
	for (i = 0; i < n; i++)
	{
		num = num + str[i] - '0';
	}

	printf("%d", num);

	return 0;
}