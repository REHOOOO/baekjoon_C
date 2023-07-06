#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int a, b, v;
	int cnt = 0;
	int h = 0;

	scanf("%d %d %d", &a, &b, &v);

	
	if ((v - b) % (a - b) != 0)
	{
		printf("%d", (v - b) / (a - b) + 1);
	}
	else
	{
		printf("%d", (v - b) / (a - b));
	}

	return 0;
}