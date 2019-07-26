Cunninghamg [1:10 PM]
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>


static void
load(
 char const * const filename,
 int * const np,
 float ** const ap
)
{
int i, j, n, ret;
 FILE * fp=NULL;
 float * a;

 // open the file
 fp = fopen(filename, "r");

 assert(fp);

 //number of nodes found in file

 ret = fscanf(fp, "%d", &n);
  //allocate memory for local values

 a = malloc(n*n*sizeof(*a));
 assert(a);



}
