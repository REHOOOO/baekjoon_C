#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if ((a == b) && (b == c))
	{
		printf("%d", 10000 + a * 1000);
	}
	else if (a != b)	// a b가 다를 때 
	{
		if ((a == c) || (b == c))	// a b가 다를 때 같은 눈이 2개 나오는 경우
		{
			printf("%d", 1000 + c * 100);
		}
		else
		{
			for ()
		}
	}


	return 0;
}