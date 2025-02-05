#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct // 점을 나타내는 구조체
{
	int x, y;
} point;

// CCW 알고리즘
int ccw(point a, point b, point c)
{
	long long int result = (long long int)(b.x - a.x) * (c.y - a.y) - (long long int)(b.y - a.y) * (c.x - a.x);
	if (result > 0)			// 반시계 방향
	{
		return 1;
	}
	else if (result < 0)	// 시계 방향
	{
		return -1;
	}
	else                    // 일직선 상
	{
		return 0;
	}
}

int main()
{
	point A, B, C, D;

	scanf("%d %d %d %d", &A.x, &A.y, &B.x, &B.y);
	scanf("%d %d %d %d", &C.x, &C.y, &D.x, &D.y);

	//////// 교차 판별 ////////
	int ab = ccw(A, B, C) * ccw(A, B, D);
	int cd = ccw(C, D, A) * ccw(C, D, B);

	// 일반적인 교차 판별
	if (ab <= 0 && cd <= 0)
	{
		// 일직선 상에 있을 때, 겹치는지 확인 (예외상황)
		if (ab == 0 && cd == 0)
		{
			// A < B, C < D 일 때 C <= B 이고 A <= D 이면 겹침
			if (A.x > B.x || (A.x == B.x && A.y > B.y))
			{
				point temp = A;	// AB를 swap해 A < B로 만들어 줌 
				A = B;
				B = temp;
			}
			if (C.x > D.x || (C.x == D.x && C.y > D.y))
			{
				point temp = C;	// CD를 swap해 C < D로 만들어 줌
				C = D;
				D = temp;
			}
			if ((C.x <= B.x && A.x <= D.x) && ((C.y <= B.y && A.y <= D.y)))	// C <= B 이고 A <= D
			{
				printf("1");
				return 0;
			}
			else
			{
				printf("0");
				return 0;
			}
		}
		printf("1");
		return 0;
	}
	printf("0");
	return 0;
}