#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int t, r;
	int i, j, k;
	char s[21];

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &r);
		scanf("%s", s);
		for (j = 0; s[j]; j++)
		{
			for (k = 0; k < r; k++)
			{
				printf("%c", s[j]);
			}
		}
		printf("\n");
	}

	return 0;
}