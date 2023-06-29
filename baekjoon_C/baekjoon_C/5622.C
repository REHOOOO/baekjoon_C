#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[18];
	int cnt = 0;
	int i;

	scanf("%s", str);

	for (i = 0; str[i]; i++)
	{
		if (str[i] <= 'C')
		{
			cnt = cnt + 3;
		}
		else if (str[i] <= 'F')
		{
			cnt = cnt + 4;
		}
		else if (str[i] <= 'I')
		{
			cnt = cnt + 5;
		}
		else if (str[i] <= 'L')
		{
			cnt = cnt + 6;
		}
		else if (str[i] <= 'O')
		{
			cnt = cnt + 7;
		}
		else if (str[i] <= 'S')
		{
			cnt = cnt + 8;
		}
		else if (str[i] <= 'V')
		{
			cnt = cnt + 9;
		}
		else if (str[i] <= 'Z')
		{
			cnt = cnt + 10;
		}
	}

	printf("%d", cnt);

	return 0;
}