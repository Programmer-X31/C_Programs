#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#undef swap

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))
#define LIMIT 100000
#define SAMPLE_SIZE 10

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

void swap(int v[], int i, int j)
{
	int c = v[i];
	v[i] = v[j];
	v[j] = c;
}

void bubble_sort(int arr[], size_t len)
{
	if (len < 2)
		return;

	int i, j;

	bool run = true;
	while (run)
	{
		for (i = 0; i < len - 1; i++)
		{
			run = false;
			for (j = 0; j < len - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr, j, (j + 1));
					run = true;
				}
			}
		}
	}
}

void shell_sort(int v[], int n)
{
	int gap, i, j, tmp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				swap(v, j, (j + gap));
			}
}

void q_sort(int v[], int left, int right)
{
	int i, last;
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	q_sort(v, left, last - 1);
	q_sort(v, last + 1, right);
}

void printarray(int v[], size_t len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf(ANSI_COLOR_GREEN "%d, " ANSI_COLOR_RESET, v[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	clock_t strt, end; // CPU Usage
	float cpu_time_used;
	int arr[1000];

	FILE *fptr;
	fptr = fopen("/home/sachin/My_Projects/C/Practice/assets/array.txt", "a");

	for (int i = 0; i < LIMIT; i++)
	{
		float total = 0.0;
		float avg = 0.0;

		for (int j = 0; j < SAMPLE_SIZE; j++)
		{
			for (int k = 0; i < 1000; i++)
			{
				arr[i] = rand() % LIMIT + 1;
			}

			strt = clock();
			shell_sort(arr, 1000);
			end = clock();
			cpu_time_used = ((double)(end - strt)) / CLOCKS_PER_SEC;
			total += cpu_time_used;
			// printf("Time taken (Shell Sort):  %f sec\n", cpu_time_used);
		}
		avg = total / ((float)SAMPLE_SIZE);
		fprintf(fptr, "%f, \n", avg);
		printf("%f\n", avg);
	}

	fclose(fptr);
}