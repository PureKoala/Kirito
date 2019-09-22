#include<stdio.h>
#include<string.h>

int main()
{
	char a[14];
	gets_s(a);
	int i = 1;
	int sum = 0;
	for (int p = 0; p < 12; p++)
	{
		if (a[p] == '-')
			continue;
		sum = sum + i * (a[p] - 48);
		i++;
	}
	if ((a[12] - 48) == (sum % 11))
		printf("Right");
	else
	{
		a[12] = (sum % 11) + 48;
		for (int p = 0; p < 13; p++)
			putchar(a[p]);
	}
	while (1);
	return 0;
}