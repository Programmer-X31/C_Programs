#include <stdio.h>
#include <ctype.h>

#define MAX 5

int power(int base, int power);
int atoi(char s[]);

int main()
{
	/* Initialisation */
	char s[MAX];
	int i, c;

	printf("Enter year: ");
	for (i = 0; i < MAX+1 && (c = getchar()) != '\n'; ++i) 
		s[i] = c;
	s[++i] = '\0';						/* Escape Character at the end */
	
	int year = atoi(s);
	
	if (year % 400 == 0) {
		printf("%d is a leap year.", year);
	} else if (year % 100 == 0) {
		printf("%d is not a leap year.", year);
	} else if (year % 4 == 0) {
		printf("%d is a leap year.", year);
	} else {
		printf("%d is not a leap year.", year);
	}
	
	return 0;
}

int atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; isdigit(s[i]); ++i) 
		n = 10 * n + (s[i] - '0');		/* Since each place value increases by 10 */
	return n;
}


int power(int n1, int n2) /* Iterative Function; Can use Recursion */
{
	int i, p;
	p = 1;
	for (i = 1; i <= n2; ++i)
		p = p * n1;
	return p;
}
