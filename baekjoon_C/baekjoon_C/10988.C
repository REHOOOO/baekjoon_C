#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main()
{
	char str[105];
	int i;
	int flag = 1;

	scanf("%s", str);
	int len = strlen(str);

	for (i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			flag = 0;
			break;
		}
	}

	printf("%d", flag);

	return 0;
}