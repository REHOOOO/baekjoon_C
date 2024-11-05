#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int V, E;
	int i;
	int a, b, c;
	int tree[100000][10000]={0,};

	scanf("%d %d", &V, &E);

	for(i=0;i<E;i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		tree[a][b]=c;
		tree[b][a]=c;
	}
}