#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[105];
	int a[26] = { 0, };
	int n;
	int i,j;
	int flag = 0;
	int cnt = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 26; j++)
		{
			a[j] = 0;
		}
		flag = 0;

		scanf("%s", str);
		for (j = 0; str[j]; j++)
		{
			if (a[str[j] - 'a'] == 1)
			{
				if (str[j] != str[j - 1])
				{
					flag = 1;
					break;
				}
			}
			a[str[j] - 'a'] = 1;
		}

		if (flag == 0)
		{
			cnt = cnt + 1;
		}
	}

	printf("%d", cnt);

	return 0;
}