#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[2][1002];
int grid[1001][1001];

void backtracking(int i, int j)
{
	if (grid[i][j] == 0)	// 0에 도달했다면 
	{
		return;
	}
	if (str[0][i] == str[1][j]) // 같은 문자라면 
	{
		backtracking(i - 1, j - 1); // 왼쪽 위 좌표를 backtracking 한다
		printf("%c", str[0][i]); // 문자를 출력
	}
	else // 다른 문자라면
	{
		if (grid[i - 1][j] >= grid[i][j - 1])	// 왼쪽과 위쪽 중 더 큰 위치로 backtracking
		{
			backtracking(i - 1, j);
		}
		else
		{
			backtracking(i, j-1);
		}
	}
}

int main()
{
	str[0][0] = '0';	// 마진을 위해 필요없는 값을 넣어둔다
	str[1][0] = '0';

	scanf("%s", &str[0][1]);
	scanf("%s", &str[1][1]);

	int i, j;
	int x = 0;
	int y = 0;

	/// grid 생성
	for (i = 0; i <= 1001; i++)
	{
		if (str[0][i] == '\0')	// str[0] 문자열의 끝
		{
			x = i - 1;
			break;
		}
		for (j = 0; j <= 1001; j++)
		{
			if (str[1][j] == '\0')	// str[1] 문자열의 끝 
			{
				y = j - 1;
				break;
			}

			if (i == 0 || j == 0)	// 마진 설정
			{
				grid[i][j] = 0;
			}
			else if(str[0][i]==str[1][j])	// 같은 문자라면
			{
				grid[i][j] = grid[i - 1][j - 1] + 1;
			}
			else // 다른 문자라면 
			{
				if (grid[i - 1][j] >= grid[i][j - 1])	// grid[i][j]의 왼쪽과 위쪽 중 더 큰 숫자를 저장
				{
					grid[i][j] = grid[i - 1][j];
				}
				else
				{
					grid[i][j] = grid[i][j - 1];
				}
			}
		}
	}
	
	/// 역추적
	int len = 0;

	len = grid[x][y];

	if (len == 0)	// LCS의 길이가 0인 경우
	{
		printf("%d", len);
	}
	else
	{
		printf("%d\n", len);
		backtracking(x, y);
	}

}