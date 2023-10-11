#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;
	int i, j;
	int temp;
	char num[100];
	int maze[100][100] = { 0, };

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", &num);
		for(j=0;j<m;j++)
		{
			if(num[j]=='1')
			{
				maze[j][i]=1;
			}
		}

		
	}

	return 0;
}