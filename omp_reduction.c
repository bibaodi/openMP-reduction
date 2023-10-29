/******************************************************************************
* FILE: omp_reduction.c
* DESCRIPTION:
*   OpenMP Example - Combined Parallel Loop Reduction - C/C++ Version
*   This example demonstrates a sum reduction within a combined parallel loop
*   construct.  Notice that default data element scoping is assumed - there
*   are no clauses specifying shared or private variables.  OpenMP will 
*   automatically make loop index variables private within team threads, and
*   global variables shared.
* AUTHOR: Blaise Barney  5/99
* LAST REVISED: 04/06/05
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NNN 999

int main (int argc, char *argv[]) 
{
int   i, n;
float a[NNN], b[NNN], sum; 

/* Some initializations */
n = NNN;
for (i=0; i < n; i++){
  a[i] = b[i] = i * 1.0;
}
sum = 0.0;

//time-begin
clock_t start, end;
double cpu_time_used;

start = clock();

#pragma omp parallel for reduction(+:sum)
for (i=0; i < n; i++){
    sum = sum + (a[i] * b[i]);
}

//time-end
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

printf("   Sum = %f, timeDelta=%f\n",sum, cpu_time_used);
return 0;
}
