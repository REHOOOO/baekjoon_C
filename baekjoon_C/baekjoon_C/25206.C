#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

int main()
{
	char str[55];
	char str1[5];
	int i;
	float score;
	float total = 0;
	int sum = 0;

	for (i = 0; i < 20; i++)
	{
		scanf("%s", str);
		scanf("%f", &score);
		scanf("%s", str1);

		if (strcmp(str1, "A+") == 0)
		{
			sum = sum + score;
			total = total + (score * 4.5);
		}
		else if (strcmp(str1, "A0") == 0)
		{
			sum = sum + score;
			total = total + (score * 4.0);
		}
		else if (strcmp(str1, "B+") == 0)
		{
			sum = sum + score;
			total = total + (score * 3.5);
		}
		else if (strcmp(str1, "B0") == 0)
		{
			sum = sum + score;
			total = total + (score * 3.0);
		}
		else if (strcmp(str1, "C+") == 0)
		{
			sum = sum + score;
			total = total + (score * 2.5);
		}
		else if (strcmp(str1, "C0") == 0)
		{
			sum = sum + score;
			total = total + (score * 2.0);
		}
		else if (strcmp(str1, "D+") == 0)
		{
			sum = sum + score;
			total = total + (score * 1.5);
		}
		else if (strcmp(str1, "D0") == 0)
		{
			sum = sum + score;
			total = total + (score * 1.0);
		}
		else if (strcmp(str1, "F") == 0)
		{
			sum = sum + score;
			total = total + (score * 0);
		}
	}

	printf("%f", total / sum);

	return 0;
}