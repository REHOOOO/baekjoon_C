#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int solution[5000] = { 0, };

int main()
{
	int n;
	int i, j;
	long long int min = 4000000000;
	int result[3] = { 0, };
	int temp;
	int left, right;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &solution[i]);
	}

	///// 버블 정렬 /////
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(solution[j]>solution[j+1])
			{
				temp = solution[j];
				solution[j] = solution[j+1];
				solution[j+1] = temp;
			}
		}
	}

	for (i = 0; i < n-2; i++)
	{
		left = i+1;
		right = n - 1;

		while (solution[left] < solution[right])
		{
			long long int calc = solution[i] + solution[left] + solution[right];	// 계산값

			if (calc == 0)	// 계산값이 0일 경우
			{
				min = abs(calc);
				result[0] = solution[i];
				result[1] = solution[left];
				result[2] = solution[right];
				break;
			}
			else if (min > abs(calc))	// 계산값이 min보다 작을 경우
			{
				min = abs(calc);
				result[0] = solution[i];
				result[1] = solution[left];
				result[2] = solution[right];
			}

			if (calc > 0)	// 계산값이 양수일 경우
			{
				right--;
			}
			else if (calc < 0)	//계산값이 음수일 경우
			{
				left++;
			}
		}

		if (min == 0)
		{
			break;
		}
	}

	printf("%d %d %d", result[0], result[1], result[2]);

	return 0;
}