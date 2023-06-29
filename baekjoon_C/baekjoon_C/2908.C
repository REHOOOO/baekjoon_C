#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char a[5];
	char b[5];
	int i, j;

	scanf("%s %s", a, b);

	for (i = 2; i >= 0; i--)
	{
		if (a[i] > b[i])
		{
			for (j = 2; j >= 0; j--)
			{
				printf("%c", a[j]);
			}
			break;
		}
		else if (a[i] < b[i])
		{
			for (j = 2; j >= 0; j--)
			{
				printf("%c", b[j]);
			}
			break;
		}
	}

	return 0;
}