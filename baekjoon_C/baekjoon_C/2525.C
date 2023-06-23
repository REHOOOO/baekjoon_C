#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int H, M, m, t, tt;
	scanf("%d %d", &H, &M);
	scanf("%d", &m);
	t = M + m; // 분 계산
	tt = H + (t / 60); // 시 계산

	if (t < 60)
	{
		printf("%d %d", H, t);
	}
	else if (t >= 60)
	{
		if (tt >= 24)
		{
			printf("%d %d", tt - 24, t % 60);
		}
		else if (tt < 24)
		{
			printf("%d %d", tt, t % 60);
		}
	}
	return 0;
}