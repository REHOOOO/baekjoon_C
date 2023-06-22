#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	printf("%d\n", a * (b % 10)); // 1의 자리
	printf("%d\n", a * ((b / 10) % 10));	// 10의 자리	
	printf("%d\n", a * (b / 100));	// 100의 자리
	printf("%d\n", a * b );

	return 0;
}