#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) { //오름차 순으로 정렬 
	return (*(int*)a - *(int*)b);
}

int solution[5000] = { 0, };

int main()
{
	int n;
	int i;
	long long int min = 5000000000;
	int result[3] = { 0, };
	int left, right;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &solution[i]);
	}

	qsort(solution, n, sizeof(int), compare);

	for (i = 0; i < n-2; i++)
	{
		left = i + 1;
		right = n - 1;

		while (left < right)
		{
			long long int calc = (long long int)solution[i] + solution[left] + solution[right];	// 계산값

			

			if (calc == 0)	// 계산값이 0일 경우
			{
				min = llabs(calc);
				result[0] = solution[i];
				result[1] = solution[left];
				result[2] = solution[right];
				break;
			}
			else if (min > llabs(calc))	//계산값이 min보다 작을 경우
			{
				min = llabs(calc);
				result[0] = solution[i];
				result[1] = solution[left];
				result[2] = solution[right];
			}

			if (calc > 0)	// 계산값이 양수일 경우
			{
				right--;
			}
			else if (calc < 0)	// 계산값이 음수일 경우
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