#include "myhead.h"
#include<math.h>
#include<time.h>
#include<windows.h>
void showarray(const double ar[], int n);
double * new_d_array(int n, ...);
int main()
{
	double *p1, *p2;
	p1 = new_d_array(5,1.2,2.3,3.4,4.5,5.6);
	p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
	showarray(p1, 5);
	showarray(p2, 4);
	free(p1);
	free(p2);
	while (1);
	return 0;
}
double * new_d_array(int n, ...)
{
	double *msc = (double *)malloc(n * sizeof(double));
	va_list ap;
	va_start(ap, n);
	for (int i = 0; i < n; i++)
		*(msc + i) = va_arg(ap, double);
	va_end(ap);
	return msc;
}
void showarray(const double ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%.2lf  ", ar[i]);
	}
	printf("\n");
}