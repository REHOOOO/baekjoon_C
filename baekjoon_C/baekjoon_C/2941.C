#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[105];
	int i;
	int cnt = 0;

	scanf("%s", str);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == 'c' && str[i + 1] == '=') // c=
		{
			cnt = cnt + 1;
			i = i + 1;
		}
		else if (str[i] == 'c' && str[i + 1] == '-') // c-
		{
			cnt = cnt + 1;
			i = i + 1;
		}
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') // dz=
		{
			cnt = cnt + 1;
			i = i + 2;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j') // lj
		{
			cnt = cnt + 1;
			i = i + 1;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j') // nj
		{
			cnt = cnt + 1;
			i = i + 1;
		}
		else if (str[i] == 's' && str[i + 1] == '=') // s=
		{
			cnt = cnt + 1;
			i = i + 1;
		}
		else if (str[i] == 'z' && str[i + 1] == '=') // z=
		{
			cnt = cnt + 1;
			i = i + 1;
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			cnt = cnt + 1;
		}
	}

	printf("%d", cnt);

	return 0;
}