#include "myhead.h"
#include<math.h>
#include<time.h>
#include<windows.h>
typedef struct names
{
	char first[40];
	char last[40];
}names;
names vals[100];
void fillarray(names ar[], int n);
void showarray(const names ar[], int n);
int mycomp(const void *p1, const void *p2);
int main()
{
	fillarray(vals, 100);
	puts("Random list:\n");
	showarray(vals, 100);
	qsort(vals, 100, sizeof(names), mycomp);
	puts("Orderer one:");
	showarray(vals, 100);
	while (1);
	return 0;

}
void fillarray(names ar[], int n)
{
	int index;
	int x;
	srand((unsigned int)time(0));
	for (index = 0; index < n; index++)
	{
		x = rand() % 10 + 1;
		for (int i = 0; i < x; i++)
		{
			ar[index].first[i] = rand() % 26 + 'a';
		}
		x = rand() % 10 + 1;
		for (int i = 0; i < x; i++)
		{
			ar[index].last[i] = rand() % 26 + 'a';
		}
	}
}
void showarray(const names ar[], int n)
{
	int index;
	for (index = 1; index < n; index++)
	{
		printf("%10s.%-10s",ar[index].first,ar[index].last);
		if (index % 4 == 3)
			putchar('\n');
	}
	if(index%4!=0)
		putchar('\n');
}
int mycomp(const void *p1, const void *p2)
{
	const names *ps1 = (const names *)p1;
	const names *ps2 = (const names *)p2;
	int x = strcmp(ps1->first, ps2->first);
	if (x != 0)
	{
		return x;
	}
	else
		return strcmp(ps1->last, ps2->last);
}