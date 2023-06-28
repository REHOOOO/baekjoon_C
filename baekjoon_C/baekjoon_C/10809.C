#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char s[101];
	int i, j;

	scanf("%s", s);

	for (i = 'a'; i <= 'z'; i++)
	{
		for (j = 0; j<=100; j++)
		{
			if (s[j] == '\0')
			{
				printf("-1 ");
				break;
			}
			else if (s[j] == i)
			{
				printf("%d ", j);
				break;
			}
		}
	}

	return 0;
}