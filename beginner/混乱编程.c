#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=149,b,c,kirito[9],p=0,q;
	for (; a<333; a++)
	{
		b = 2 * a;c = 3 * a;
		kirito[0] = a % 10;kirito[1] = (a / 10) % 10;kirito[2] = a / 100;kirito[3] = b % 10;kirito[4] = (b / 10) % 10;
		kirito[5] = b / 100;kirito[6] = c % 10;kirito[7] = (c / 10) % 10;kirito[8] = c / 100;
		while(p<8){ q = p + 1;
			while (q < 9) if (kirito[q++] == kirito[p]) break;if ((kirito[p] == 0) || (kirito[q] == kirito[p])) break;
			else p++;}
		if ((kirito[p] == 0)|| (kirito[q] == kirito[p])) continue;
		printf("%d %d %d\n", a, b, c);
	}
}
