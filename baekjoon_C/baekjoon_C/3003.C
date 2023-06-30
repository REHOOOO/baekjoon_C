#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i;
	int n;
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &n);
		if (i <= 1)
		{
			printf("%d ", 1 - n);
		}
		else if (i <= 4)
		{
			printf("%d ", 2 - n);
		}
		else if (i <= 5)
		{
			printf("%d ", 8 - n);
		}
	}

	return 0;
}