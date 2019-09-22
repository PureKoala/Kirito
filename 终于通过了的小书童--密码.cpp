#include <stdio.h>
#include<ctype.h>
int main()
{
	int a;
	char u;
	scanf("%d", &a);
	char ch;
	char p[51];
	fgets(p, 50, stdin);
	int n = 0;
	while (scanf("%c", &ch) == 1 && isalpha(ch))
	{
		int t = (int)ch + a;
		while (t > 122)
			t = t - 26;
		p[n] = t;
		n++;
	}
	for (int y = 0; y < n; y++)
	{
		printf("%c", p[y]);
	}
	return 0;
}