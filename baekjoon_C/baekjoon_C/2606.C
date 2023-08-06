#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, num;
	int com[100] = { 0, };
	com[0] = 1;
	int pair[10000][2] = { 0, };
	int i;
	int c1, c2;
	int cnt = 0;

	scanf("%d", &n);
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &c1, &c2);
		c1 = c1 - 1;
		c2 = c2 - 1;
		pair[i][0] = c1;
		pair[i][1] = c2;

		if ((com[c1] == 1 && com[c2] == 0) || (com[c1] == 0 && com[c2] == 1))
		{
			cnt = cnt + 1;
			com[c1] = 1;
			com[c2] = 1;
		}
	}

	for (i = 0; i < num; i++)
	{
		c1 = pair[i][0];
		c2 = pair[i][1];
		if ((com[c1] == 1 && com[c2] == 0) || (com[c1] == 0 && com[c2] == 1))
		{
			cnt = cnt + 1;
			com[c1] = 1;
			com[c2] = 1;
		}
	}

	printf("%d", cnt);

	return 0;
}