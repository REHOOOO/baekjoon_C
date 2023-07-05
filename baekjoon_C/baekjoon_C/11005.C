#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int b;
	int n;
	int i, j;
	int num = 1;
	char total[50];

	scanf("%d", &n);
	scanf("%d", &b);

	for (i = 48; i >= 0; i--)
	{
		if (n % b >= 10)
		{
			total[i] = (n % b) - 10 + 'A';
		}
		else
		{
			total[i] = (n % b) + '0';
		}
		
		n = n / b;

		if (n == 0)
		{
			break;
		}
	}

	for (j = i; j < 49; j++)
	{
		printf("%c", total[j]);
	}

	return 0;
}