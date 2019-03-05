/* 
   A C program meant to be used with the Mersenne Twister code in order to 
   replace reliance on the R standalone library if it is only being used
   to generate from a uniform distribution. It will not be exactly the same
   for the same seeds as the R library, however, it will be reproducible. 

   Run set_seed() with two integers as before, then use runif() as before.

   The mt19937ar files are copyright their original owners subject to their
   terms. See those files for details.

   This file is released under the GPL-3 or any later compatible GPL license.


   Feedback is quite welcome!

   Geoffrey Thompson, 3/2019
   Iowa State University, Dept of Statistics
   gzthompson@gmail.com

 */
#include <stdio.h>
#include "mt19937ar.h"
#include "replaceR.h"

void set_seed(unsigned int x, unsigned int y) {
  unsigned long init_key[2] = {(unsigned long) x, (unsigned long) y};
  init_by_array(init_key, 2);
}

double runif(double lower, double upper) {
  double x = genrand_real2();
  return (lower + x * (upper - lower)) ;  
}