#include<stdlib.h>
double * ptd;
ptd = (double *) malloc(30 * sizeof(double));
if (ptd == NULL)
{
    puts("Bye");
    exit(EXIT_FAILURE);
}
free (ptd);