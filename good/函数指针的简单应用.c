
#include <stdio.h>

 

double sqrt(double);

void transform(double *, double *, int, double (*fun)(double));

 

int main(void)

{

    double source[5] = {2.2,4,5,6.3,0.1};

    double target[5];

 

    transform(source, target, 5, sqrt);

    for(int i = 0; i < 5; i++)

    {

        printf("Target[%d] = %.4f\n", i, target[i]);

    }

 

    return 0;

}

 

double sqrt(double x)

{

    return (x * x);

}

 

void transform(double * sou, double * tar, int n, double (*fun)(double))

{

    int i;

 

    for(i = 0; i < n; i++)

    {

        tar[i] = fun(sou[i]);

    }

}
