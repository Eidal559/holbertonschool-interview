#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - Finds the maximum number in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sorts an array by a specific digit place.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The digit place (1s, 10s, 100s).
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t i;
	int j;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Count occurrences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Convert count to positions */
	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	/* Build output array */
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	/* Copy back sorted elements */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array using LSD Radix Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	/* Apply counting sort for each digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
