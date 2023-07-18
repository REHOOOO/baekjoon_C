#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[10000] = { 0, };
	int i;
	int temp;

	for (i = 1; i <= 10000; i++)
	{
		temp = i / 1000 + ((i / 100) % 10) + ((i / 10) % 10) + i % 10 + i;
		if (temp <= 10000)
		{
			num[temp - 1] = 1;
		}
	}

	for (i = 0; i < 10000; i++)
	{
		if (num[i] == 0)
		{
			printf("%d\n", i + 1);
		}
	}

	return 0;
}