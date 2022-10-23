#include <stdio.h>

void fib(double[], int, int);

int main(int argc, char *argv[])
{
	double f[100];

	fib(f, 10, 10);

   /*  for(int i = 0; i < 10; i++) */
		/* printf("%.0f", f[i]); */


}


void fib(double arr[], int s, int len)
{
	double x = 0, y = 1, z, *ip;

	for(ip = arr; ((ip - arr) < s) && ((ip - arr) < len); ip++) {
		if(ip == arr)
			*ip = x;
		else if (ip == (arr+1))
			*ip = y;
		else {
			z = x + y;
			*ip = z;
			x = y;
			y = z;
		}
		printf("%.0f\n", *ip);
	}
}
