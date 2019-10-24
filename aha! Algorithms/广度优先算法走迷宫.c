#include "myhead.h"
struct note
{
	int x;
	int y;
	int s;
};
int main()
{
	struct note que[2501];
	int map[51][51] = {0};
	int walked[51][51] = {0};
	int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	scanf("%d %d", &n, &m);
	for(i=1;i<=n;i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	scanf("%d %d %d %d", &startx, &starty, &p, &q);
	int head, tail;
	head = 1;
	tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].s = 0;
	tail++;
	walked[startx][starty] = 1;
	flag = 0;
	while (head < tail)
	{
		for (k = 0; k <= 3; k++)
		{
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			if (tx<1 || ty<1 || tx>n || ty>m)
			{
				continue;
			}
			if (map[tx][ty] == 0 && walked[tx][ty] == 0)
			{
				walked[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].s = que[head].s + 1;
				tail++;
			}
			if (tx == p && ty == q)
			{
				flag =1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}
	printf("%d", que[tail - 1].s);
	while (1);
	return 0;
}