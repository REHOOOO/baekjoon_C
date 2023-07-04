#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int b;
	char n[30];
	int i;
	int num = 1;
	int total = 0;
	int nn = 0;

	scanf("%s", n);
	scanf("%d", &b);

	for (i = strlen(n) - 1; i >= 0; i--)
	{
		if (n[i] >= 'A')
		{
			nn = n[i] - 'A' + 10;
		}
		else
		{
			nn = n[i] - '0';
		}

		total = total + (nn * num);
		num = num * b;
	}

	printf("%d", total);

	return 0;
}