#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[5][18];
	int i, j;

	for (i = 0; i < 5; i++)
	{
		scanf("%s", str[i]);
	}

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i < strlen(str[j]))
			{
				printf("%c", str[j][i]);
			}
		}
	}

	return 0;
}