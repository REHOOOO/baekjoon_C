#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // atoi 함수 사용

int main()
{
	int flag = 0;
	int minus = 0;
	int i, j, k;
	char str[55];
	char temp[55];
	int num = 0;

	scanf("%s", str);

	for (i = 0; i < 55; i++)
	{
		if (minus == 0) // - 가 아직 나오지 않았을 때 
		{
			if (str[i] == '+' || str[i] == '\0')
			{
				k = 0;
				for (j = flag; j < i; j++)
				{
					temp[k] = str[j];
					k++;
				}
				temp[k] = '\0';
				flag = j + 1;
				num = num + atoi(temp);
			}
			if (str[i] == '-')  // 가장 처음 -가 나오면
			{
				k = 0;
				for (j = flag; j < i; j++)
				{
					temp[k] = str[j];
					k++;
				}
				temp[k] = '\0';
				flag = j + 1;
				num = num + atoi(temp);
				minus = 1;
			}
		}
		else
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
			{
				k = 0;
				for (j = flag; j < i; j++)
				{
					temp[k] = str[j];
					k++;
				}
				temp[k] = '\0';
				flag = j + 1;
				num = num - atoi(temp);
			}
		}
	}

	printf("%d", num);
}