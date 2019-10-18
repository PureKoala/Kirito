#include "myhead.h"
#include<math.h>
#include<time.h>
#include<windows.h>
void add(Stack *ps);
void delect(Stack *ps);
int main()
{
	char p[10];
	Stack *s;
	s = (Stack *)malloc(sizeof(Stack));
	InitializeStack(s);
	srand((unsigned int)time(0));
	printf("要干个啥？\n");
	printf("Anything else to quit.\n");
	s_gets(p, 10);
	while (p[0]=='a'||p[0]=='d')
	{
		switch (p[0])
		{
		case 'a':add(s);
			break;
		case 'd':delect(s);
			break;
		default:
			break;
		}
		printf("要干个啥？\n");
		printf("Anything else to quit.\n");
		s_gets(p, 10);
	}
	printf("最后有%d个数。\n", s->top);
	free(s);
	while (1);
	return 0;
}
void add(Stack *ps)
{
	printf("加几个？\n");
	int q;
	char p[10];
	fgets(p, 10, stdin);
	q = atoi(p);
	for (int i = 0; i < q; i++)
	{
		if (FullStack(ps))
		{
			printf("满咧!\n");
			return;
		}
		else 
		{
			int t;
			t = rand() % 10;
			printf("%d\n", t);
			Push(t, ps);
			
			printf("这里面现在有%d个数。\n", ps->top );
			Sleep(500);
		}
	}
	return;
}
void delect(Stack *ps)
{
	if (EmptyStack(ps))
	{
		printf("Nothing to delect!\n");
		return;
	}
	else
	{
		printf("删了个%d\n",ps->items[--ps->top]);
		Pop(ps);
		return;
	}
}
char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() == '\n');
	}
	return ret_val;
}