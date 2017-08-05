#ifndef _MYRANDOM_H
#define _MYRANDOM_H

#include <iostream>
#include <sys/time.h>
#include <stdlib.h>   //AI lab 95-4-7 hoseini

/****************************************************************************/
/***************************   random stuff    ******************************/
/****************************************************************************/
/* From Andrew Moore's C package                                            */

/*
 * AI lab 95-4-10 hoseini start
 * the following function is never used in the base code so I comment it.
 *
*/
//void set_random_seed_from_clock()
//{
//    /* initialize the random number seed. */
//    timeval tp;
//    gettimeofday( &tp, NULL );
//    srandom( (unsigned int) tp.tv_usec );
//}
//AI lab 95-4-10 hoseini end

int int_random(int n);
float range_random(float lo, float hi);
int very_random_int(int n);


#endif
