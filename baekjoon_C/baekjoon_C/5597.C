#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j;
	int num[30];
	int stu[28];
	int flag;
	int min = 40;
	int max = 0;

	for (i = 0; i < 30; i++)
	{
		num[i] = i + 1;
	}

	for (i = 0; i < 28; i++)
	{
		scanf("%d", &stu[i]);
	}

	for (i = 0; i < 30; i++)
	{
		flag = 0;
		for (j = 0; j < 28; j++)
		{
			if (num[i] == stu[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			if (min > num[i])
			{
				min = num[i];
			}
			if (max < num[i])
			{
				max = num[i];
			}
		}
	}

	printf("%d\n", min);
	printf("%d\n", max);

	return 0;
}