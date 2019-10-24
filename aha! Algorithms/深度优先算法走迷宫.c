#include "myhead.h"
int n, m, p, q, min = 1000;
int map[51][51];
int walked[51][51];
void dfs(int x,int y,int step)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int tx, ty, k;
	if (x == p && y == q)
	{
		if (step < min)
			min = step;
		return;
	}
	for (k = 0; k <= 3; k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx<1 || ty<1 || tx>n || ty>m)
			continue;
		if (map[tx][ty] == 0 && walked[tx][ty] == 0)
		{
			walked[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			walked[tx][ty] = 0;
		}
	}
	return;
}
int main()
{
	int i, j, startx, starty;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	scanf("%d %d %d %d", &startx, &starty, &p, &q);
	walked[startx][starty] = 1;
	dfs(startx, starty, 0);
	printf("%d", min);
	while (1);
	return 0;
}