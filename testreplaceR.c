
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

compile this example program with: 

gcc mt19937ar.c replaceR.c testreplaceR.c -o testreplaceR

*/

#include <stdio.h>
#include "mt19937ar.h"
#include "replaceR.h"

int main(void){
  int i;
    unsigned long init[2]={0x123, 0x234}, length=2;

    init_by_array(init, length);

    printf("\n100 outputs of genrand_real2()\n");
    for (i=0; i<100; i++) {
      printf("%10.8f ", genrand_real2());
      if (i%5==4) printf("\n");
    }

    set_seed(0x123, 0x234);
    
    printf("\n100 outputs of runif()\n");
    for (i=0; i<100; i++) {
      printf("%10.8f ", runif(0.,1.));
      if (i%5==4) printf("\n");
    }
    
    return 0;
}
