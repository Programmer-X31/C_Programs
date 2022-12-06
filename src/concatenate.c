#include <stdio.h>
#include <string.h>

void conca(char s1[], char s2[], char s3[], char to[]);

int main(void)
{
	char s[20];
	conca("Sach", "in", "Murali", s);
	int i;
	printf("%s", s);
}

void conca(char s1[], char s2[], char s3[], char *to)
{
	char *p;

	for (p = s; *p != "\0"; p++) {
		to = s;
	}
}
