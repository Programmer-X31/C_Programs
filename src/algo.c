#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int atoi_1(char s[]);
void shell_sort(int v[], int n);
void reverse(char s[]);
void conca(char s1[], char s2[], char s3[], char to[]);


int main()
{

}

int atoi_1(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n; 
}

void shell_sort(int v[], int n)
{
	int gap, i, j, tmp;

	for (gap = n/2; gap > 0; gap /= 2) 
		for (i = gap; i < n; i++)
			for (j = gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				tmp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = tmp;
			}
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j++ ) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
