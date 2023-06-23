#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int H, M, t;
	scanf("%d %d", &H, &M);
	t = M - 45;

	if (t >= 0)
	{
		printf("%d %d", H, t);
	}
	else if (t < 0)
	{
		if (H == 0)
		{
			printf("23 %d", 60 + t);
		}
		else if (H > 0)
		{
			printf("%d %d", H - 1, 60 + t);
		}
	}
	return 0;
}