#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int V, E;
	int i;
	int tree[100000][3];

	scanf("%d %d", &V, &E);

	for(i=0;i<E;i++)
	{
		scanf("%d %d %d", &tree[i][0], &tree[i][1], &tree[i][2]);
	}
}