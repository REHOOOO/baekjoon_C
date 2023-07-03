#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int paper[100][2];
	int i;

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &paper[i][0], &paper[i][1]);
	}
	

	return 0;
}