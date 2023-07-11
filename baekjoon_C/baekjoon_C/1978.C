#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int i, j;
	int cnt = 0;
	int num;
	int flag;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);

		flag = 0;
		for (j = 2; j < num; j++)
		{
			if (num % j == 0)
			{
				flag = 1;
				break;
			}
		}
		
		if (num != 1)
		{
			if (flag == 0)
			{
				cnt = cnt + 1;
			}
		}	
	}

	printf("%d", cnt);

	return 0;
}