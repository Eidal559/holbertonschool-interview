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
    int max = array[0];
    for (size_t i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort - Sorts an array by a specific digit place.
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The digit place (1s, 10s, 100s).
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    if (!output)
        return;

    /* Count occurrences of each digit */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Convert count to positions */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build output array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy back sorted elements */
    for (size_t i = 0; i < size; i++)
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
    if (!array || size < 2)
        return;

    int max = get_max(array, size);

    /* Apply counting sort for each digit */
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}
