#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932

long double rad_to_deg(double rad)
{
	return (180.0 * rad) / PI;
}

long double deg_to_rad(double deg)
{
	return (PI * deg) / 180.0;
}

int main()
{
	double x = deg_to_rad(30);
	printf("%f", x);
}
