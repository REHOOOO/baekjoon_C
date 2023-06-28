#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[1000];
	int i;
	int cnt = 0;

	scanf("%s", str);

	for (i = 0; i < 1000; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
		cnt = cnt + 1;
	}
	printf("%d", cnt);

	return 0;
}