#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int cnt = 0;
	int stick = 64;
	
	scanf("%d", &x);

	while (1)
	{
		if (x < stick)
		{
			stick = stick / 2;
		}
		else if (x > stick)
		{
			x = x - stick;
			cnt = cnt + 1;
		}
		else
		{
			cnt = cnt + 1;
			break;
		}

	}

	printf("%d", cnt);

	return 0;
}