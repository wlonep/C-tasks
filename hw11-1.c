#include <stdio.h>
#pragma warning(disable:26451)

int hw111(void)
{
	int i, j;
	int* pi = &i, * pj = &j;
	*pi = 5;
	*pj = 10;

	double avg;
	double* pavg = &avg;
	*pavg = (double) (i + j) / 2;
	
	printf("%d %d %lf\n", *pi, *pj, *pavg);
	printf("%d %d %lf", i, j, avg);
}