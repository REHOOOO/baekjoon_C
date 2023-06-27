#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define number 42


int main()
{
	int i, j;
	int num[10];
	int cnt = 0;
	int temp;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
		num[i] = num[i] % number;
	}

	for (i = 0; i < 10; i++)
	{
		temp = num[i];
		if (temp >= 0)
		{
			for (j = 0; j < 10; j++)
			{
				if (temp == num[j])
				{
					num[j] = -1;
				}
			}
			cnt = cnt + 1;
		}
		
	}

	printf("%d", cnt);

	return 0;
}