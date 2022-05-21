#include <stdio.h>

#define  MIN   -100      /*    Min Limit    */
#define  MAX   300       /*    Max Limit    */
#define  STEP  20		 /* Amount of Jumps */

void main() 
{
	int fahr; 

	for (fahr = MIN; fahr < MAX; fahr = fahr + STEP)
	{
		printf("%3d %6.1f\n", fahr, (5.0/9.0) *(fahr - 32));
	}
}