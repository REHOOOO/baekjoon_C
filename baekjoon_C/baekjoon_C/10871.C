#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int n, x, i;
	int num = 0;
	
	scanf("%d %d", &n, &x);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (x > num)
		{
			printf("%d ", num);
		}
	}

	return 0;
}