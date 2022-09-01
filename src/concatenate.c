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

void conca(char s1[], char s2[], char s3[], char to[])
{
	const int total_size = strlen(s1) + strlen(s2) + strlen(s3); /* +1 for escape character \0 */
	int i;

	int sizes[3] = {
		strlen(s1),
		strlen(s1) + strlen(s2),
		strlen(s1) + strlen(s2) + strlen(s3)};

	for (i = 0; i < total_size; ++i)
	{
		if (i >= 0 && i < sizes[0])
			to[i] = s1[i];

		else if (i >= sizes[0] && i < sizes[1])
			to[i] = s2[i - sizes[0]];

		else if (i >= sizes[1] && i < sizes[2])
			to[i] = s3[i - sizes[1]];
	}

	to[++i] = '\0';
}