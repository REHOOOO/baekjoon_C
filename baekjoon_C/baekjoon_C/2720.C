#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int t, c;
	int i;
	
	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &c);

		printf("%d ", c / 25); // ����
		c = c % 25;
		printf("%d ", c / 10); // ����
		c = c % 10;
		printf("%d ", c / 5); // ����
		c = c % 5;
		printf("%d\n", c / 1); // ���
	}

	return 0;
}