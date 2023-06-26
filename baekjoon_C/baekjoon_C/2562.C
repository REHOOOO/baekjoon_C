#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define number 9

int main()
{
	int num[number];
	int i;
	int max = 0;

	for (i = 0; i < number; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] > num[max])
		{
			max = i;
		}
	}
	printf("%d\n", num[max]);
	printf("%d", max + 1);

	return 0;
}