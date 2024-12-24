#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Restores the heap property by sifting down
 * @array: The array to be heapified
 * @size: The total size of the array
 * @root: The root index to start sifting down from
 * @end: The last index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left <= end && array[left] > array[largest])
		largest = left;

	if (right <= end && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size); /* Print array after swap */
		sift_down(array, size, largest, end);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i, end;

	if (!array || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	/* Extract elements from the heap */
	for (end = size - 1; end > 0; end--)
	{
		swap(&array[0], &array[end]); /* Move current root to end */
		print_array(array, size);    /* Print array after swap */
		sift_down(array, size, 0, end - 1); /* Restore heap property */
	}
}
