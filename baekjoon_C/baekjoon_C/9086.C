#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[1000];
	int i, j;
	int t;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%s", str);
		printf("%c", str[0]);
		for (j = 0; j < 1000; j++)
		{
			if (str[j] == '\0')
			{
				printf("%c\n", str[j - 1]);
				break;
			}
		}
	}

	return 0;
}