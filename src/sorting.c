#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#undef swap

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))
#define LIMIT 100000

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
	swap(v, left, (left + right) / 2); // Swapping the pivot with the first elem
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
	float cpu_time_used, cpu_time_used_b;

	unsigned int n;
	printf("Enter Length of Array: ");
	scanf("%d", &n);

	while (n <= 0)
	{
		printf("Enter Length of Array: ");
		scanf("%d", &n);
	}
	int arr1[n];
	int arr2[n];
	int arr3[n];

	printf("\nUnsorted Array: \n");

	for (int i = 0; i < n; i++)
	{
		arr1[i] = arr2[i] = arr3[i] = rand() % LIMIT + 1;
		// printf("%d - %d - %d \n", arr1[i], arr2[i], arr3[i]);
	}
	printf("\n");

	strt = clock();
	q_sort(arr1, 0, n);
	end = clock();
	cpu_time_used = ((double)(end - strt)) / CLOCKS_PER_SEC;
	printf("Time taken (Quick Sort):  %f sec\n", cpu_time_used);

	strt = clock();
	shell_sort(arr2, n);
	end = clock();
	cpu_time_used = ((double)(end - strt)) / CLOCKS_PER_SEC;
	printf("Time taken (Shell Sort):  %f sec\n", cpu_time_used);

	strt = clock();
	bubble_sort(arr3, n);
	end = clock();
	cpu_time_used = ((double)(end - strt)) / CLOCKS_PER_SEC;
	printf("Time taken (Bubble Sort): %f sec\n", cpu_time_used);

	printf("Sorted Array: \n");
	printarray(arr1, n);
}
