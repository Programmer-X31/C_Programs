#include <stdio.h>

#undef reverse
#undef strcpy

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s); i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0');
}

int main(int argc, char *argv[])
{
	char c, n[100];
	int i = 0;
	scanf("%d", &i);
}
