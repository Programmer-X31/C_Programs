#include <stdio.h>

#define MAXLINE 1000 /* Max Limit */

int max;
char curr_line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main()
{
	int len;
	extern int max;
	extern char longest[];

	printf("Enter lines: \n");
	max = 0;
	while ((len = get_line()) > 0)
		if (len > max)
		{
			max = len;
			copy();
		}
	if (max > 0)
		printf("Longest Line: %s", longest);
	return 0;
}

int get_line(void)
{
	int c, i;
	extern char curr_line[];

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		curr_line[i] = c;
	if (c == '\n')
	{
		curr_line[i] = c;
		++i;
	}
	curr_line[i] = '\0';
	return i;
}

void copy(void)
{
	int i;
	extern char curr_line[], longest[];

	i = 0;
	while ((longest[i] = curr_line[i]) != '\0')
		++i;
}
