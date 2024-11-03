#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	int coords[10001][2];
	int i;

	/////// 입력 ///////
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &coords[i][0], &coords[i][1]);
	}


	///// 신발끈 공식 /////
	long long int Shoelace1 = 0;
	long long int Shoelace2 = 0;
	double result = 0;

	coords[N][0] = coords[0][0];
	coords[N][1] = coords[0][1];

	for (i = 0; i < N; i++)
	{
		Shoelace1 += (long long int)coords[i][0] * coords[i + 1][1];
		Shoelace2 += (long long int)coords[i + 1][0] * coords[i][1];
	}

	result = (double)(Shoelace1 - Shoelace2) / 2;

	if (result < 0)
	{
		result = result * -1;
	}

	printf("%.1lf", round(result * 10) / 10); // 그냥 .f를 사용할 경우 0.5의 경우 1이 아닌 0이 됨
}