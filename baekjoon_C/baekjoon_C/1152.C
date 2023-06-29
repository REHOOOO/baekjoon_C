#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[1000005];
	int i;
	int cnt = 0;
	int flag = 0;

	scanf("%[^\n]s", str);
	
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			if (i != 0 && str[i + 1] != '\0')
			{
				cnt = cnt + 1;
			}
			else if (i == 0 && str[i + 1] == '\0')	// 공백 하나만 입력될 경우
			{
				cnt = cnt - 1;
			}
		}
	}
	cnt = cnt + 1;

	printf("%d", cnt);

	return 0;
}