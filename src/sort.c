#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#undef swap

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))
#define LIMIT 100000	// Limit of elements in the array
#define SAMPLE_SIZE 1	// Sample Size
#define MAXELEMS 100000 // The max no of the elements the array should reach before ending

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
	if (argc != 2)
	{
		printf("usage: %s <path_to_file>", argv[0]);
		return 1;
	}

	// CPU Usage
	clock_t strt, end;
	float cpu_time_used;

	FILE *fptr; // File Pointer
	fptr = fopen(argv[1], "a");
	for (int i = 2; i < MAXELEMS; i++)
	{
		int arr[i]; // 'i' here acts as a length of the array needed.

		float total = 0.0f;
		float avg = 0.0f;
		for (int arrayindex = 0; arrayindex < i; arrayindex++)
		{
			arr[arrayindex] = rand() % LIMIT + 1; // Populating the array
		}

		for (int j = 0; j < SAMPLE_SIZE; j++) // The same test is run SAMPLE_SIZE number of times in order to gain good results
		{
			strt = clock();
			shell_sort(arr, i);
			end = clock();
			cpu_time_used = ((double)(end - strt)) / CLOCKS_PER_SEC; // Default Boilerplate Code for finding time passed
			total += cpu_time_used;
		}

		avg = total / ((float)SAMPLE_SIZE);
		fprintf(fptr, "%f, \n", avg);
		printf("%f\n", avg);
	}

	fclose(fptr);
}
