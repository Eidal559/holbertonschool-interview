#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints the current subarray being searched
 * @array: The array to print
 * @start: The starting index of the subarray
 * @end: The ending index of the subarray
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_binary - Helper function to perform binary search recursively
 * @array: The array to search
 * @start: The starting index of the subarray
 * @end: The ending index of the subarray
 * @value: The value to search for
 * Return: The index where the value is located, or -1 if not found
 */
int recursive_binary(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	print_array(array, start, end);

	mid = start + (end - start) / 2;

	if (array[mid] == value && (mid == start || array[mid - 1] != value))
		return ((int)mid);

	if (array[mid] >= value)
		return (recursive_binary(array, start, mid, value));

	return (recursive_binary(array, mid + 1, end, value));
}

/**
 * advanced_binary - Searches for the first occurrence of a value
 * in a sorted array of integers using an advanced binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_binary(array, 0, size - 1, value));
}
