#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int solution[100000] = { 0, };

int main()
{
	int n;
	int i;
	double min = 3000000000;
	int result[2] = { 0, };
	int left, right;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &solution[i]);
	}

	left = 0;
	right = n - 1;

	while (solution[left] < solution[right])
	{
		double calc = solution[left] + solution[right];	// 계산값

		if (calc == 0)	// 계산값이 0일 경우
		{
			result[0] = solution[left];
			result[1] = solution[right];
			break;
		}
		else if (min > abs(calc))	// 계산값이 min보다 작을 경우
		{
			min = abs(calc);
			result[0] = solution[left];
			result[1] = solution[right];
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

	printf("%d %d", result[0], result[1]);

	return 0;
}