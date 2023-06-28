#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int M = 0;
	int n;
	double score[1000];
	int i;
	double avg = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lf", &score[i]);
		if (M < score[i])
		{
			M = score[i];
		}
	}

	for (i = 0; i < n; i++)
	{
		score[i] = score[i] / M * 100;
		avg = avg + score[i];
	}

	printf("%lf", avg / n);

	return 0;
}