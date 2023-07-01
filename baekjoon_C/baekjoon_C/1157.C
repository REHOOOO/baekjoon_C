#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int a[26] = { 0, };
	char str[1000005];
	int i;
	int max = 0;
	int num = -1;

	scanf("%s", str);

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')	// 소문자
		{
			a[str[i] - 'a'] = a[str[i] - 'a'] + 1;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') // 대문자
		{
			a[str[i] - 'A'] = a[str[i] - 'A'] + 1;
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (a[i] == max)
		{
			if (num == -1)
			{
				num = i + 'A';
			}
			else
			{
				num = '?';
				break;
			}
		}
	}

	printf("%c", num);

	return 0;
}