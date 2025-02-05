#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define min(X,Y) ((X) < (Y) ? (X) : (Y))
#define max(X,Y) ((X) > (Y) ? (X) : (Y))

typedef struct // 점을 나타내는 구조체
{
	long long int x, y;
} point;

// CCW 알고리즘
int ccw(point a, point b, point c)
{
	long long int result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
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

	scanf("%lld %lld %lld %lld", &A.x, &A.y, &B.x, &B.y);
	scanf("%lld %lld %lld %lld", &C.x, &C.y, &D.x, &D.y);

	//////// 교차 판별 ////////
	int ab = ccw(A, B, C) * ccw(A, B, D);
	int cd = ccw(C, D, A) * ccw(C, D, B);

	// 일반적인 교차 판별
	if (ab <= 0 && cd <= 0)
	{
		// 일직선 상에 있을 때, 겹치는지 확인 (예외상황)
		if (ab == 0 && cd == 0)
		{
			long long int f_min = 0;
			long long int f_max = 0;
			long long int s_min = 0;
			long long int s_max = 0;

			if (A.x == B.x && B.x == C.x && C.x == D.x)	// 두 선이 세로로 일직선 상에 있을 경우 y를 기준으로 판단
			{
				f_min = min(A.y, B.y);
				f_max = max(A.y, B.y);
				s_min = min(C.y, D.y);
				s_max = max(C.y, D.y);
			}
			else   // 세로로 일직선이 아닐경우 x를 기준으로 판단
			{
				f_min = min(A.x, B.x);
				f_max = max(A.x, B.x);
				s_min = min(C.x, D.x);
				s_max = max(C.x, D.x);
			}
			if (f_max >= s_min && s_max >= f_min)	// 각 선분의 오른쪽 부분이 다른 선분의 왼쪽과 같거나 오른쪽에 있어야 함 (x기준으로 판단할 경우)
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