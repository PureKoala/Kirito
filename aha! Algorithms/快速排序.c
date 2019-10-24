#include "myhead.h"
int a[101], n;
void sort(int left, int right)
{
	if (left > right)
		return;
	int i, j, t, temp;
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while ((temp <= a[j]) && i < j)
			j--;
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	sort(left, i - 1);
	sort(i + 1, right);
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(1, n);
	for (j = 1; j <= n; j++)
		printf("%d ", a[j]);
	while (1);
	return 0;
}