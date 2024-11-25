#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int sudoku[9][9] = { 0, };

int char2int(char s)
{
	int num = s - 48; // 0의 아스키코드값은 48
	return num;
}

int check(int i, int j, int num)
{
	for (int x = 0; x < 9; x++)
	{
		if (sudoku[i][x] == num || sudoku[x][j] == num || sudoku[i - i % 3 + x / 3][j - j % 3 + x % 3]==num) // 상하 좌우 3x3 박스에 동일한 수가 있는지 확인한다
		{
			return 0;
		}
	}
	return 1;
}

int solve()
{
	int i, j, num;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (sudoku[i][j] == 0)	// 현재 위치 숫자가 0이라면 
			{
				for (num = 1; num <= 9; num++)	// 1~9까지의 수를 대입해본다
				{
					if (check(i, j, num) == 1)
					{
						sudoku[i][j] = num;
						if (solve() == 1)	// 실행한 solve에서 1로 응답하면 그대로 1로 응답해준다
						{
							return 1;
						}
						sudoku[i][j] = 0; // solve가 1이 아니면 다시 0으로 만들어준다
					}
				}
				return 0; // 1~9 모두 들어갈 수 없다면 return 0을 한다
			}
		}
	}
	return 1; // 끝까지 가면 return 1을 한다
}


int main()
{
	int i, j;
	char str[9][10];	// null값이 들어갈 자리까지 필요

	for (i = 0; i < 9; i++)
	{
		scanf("%s", str[i]); // 입력이 빈칸이 없이 들어오기 때문에 문자열로 받은 다음 처리한다
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudoku[i][j] = char2int(str[i][j]);
		}
	}

	solve();

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d", sudoku[i][j]);
		}
		printf("\n");
	}

}