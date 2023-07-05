#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int cnt = 1;
	int num = 0;
	int room = 1;

	scanf("%d", &n);

	while (n != 1)
	{
		cnt = cnt + 1;
		num = num + 6;
		room = room + num;

		if (n <= room)
		{
			break;
		}
	}

	printf("%d", cnt);

	return 0;
}