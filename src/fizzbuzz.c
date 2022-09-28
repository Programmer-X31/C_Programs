#include <stdio.h>
#include <stdbool.h>

void fizzbuzz(const int n)
{

	for (int i = 1; i < n + 1; i++)
	{
		if (i % 3 == 0)
		{
			printf("Fizz");
			printed = true;
		}

		if (i % 5 == 0)
		{
			printf("Buzz");
			printed = true;
		}

		if (!printed)
		{
			printf("%d", i);
		}

		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int n;
	printf("Enter number for FizzBuzz: ");
	scanf("%d", &n);

	fizzbuzz(n);
}
