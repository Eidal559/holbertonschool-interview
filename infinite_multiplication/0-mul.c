#include "holberton.h"
#include <stdlib.h>

/**
 * print_error_and_exit - Prints "Error" and exits with status 98
 */
void print_error_and_exit(void)
{
    char *err = "Error\n";
    int i = 0;

    while (err[i] != '\0')
    {
        _putchar(err[i]);
        i++;
    }
    exit(98);
}

/**
 * is_digit - Checks if a string contains only digits
 * @str: The string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * print_number - Prints the digits stored in an int array (skipping leading 0s)
 * @product: Pointer to the array of integers
 * @size: The size of the array
 */
void print_number(int *product, int size)
{
    int i, started = 0;

    /* Skip leading zeros */
    for (i = 0; i < size; i++)
    {
        if (!started && product[i] == 0)
            continue; /* skip leading 0s */
        started = 1;  /* once a non-zero digit is found */
        _putchar(product[i] + '0');
    }

    if (!started)
        _putchar('0'); /* If the product was actually 0 */

    _putchar('\n');
}

/**
 * multiply - Multiplies two numeric strings and prints the result
 * @num1: First numeric string
 * @num2: Second numeric string
 */
void multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j;
    int carry, digit1, digit2, sum;
    int *product;

    /* 1. Find lengths of num1 and num2 */
    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    /* 2. Allocate product array of size len1 + len2, initialize to 0 */
    product = malloc(sizeof(int) * (len1 + len2));
    if (product == NULL)
        exit(98);
    for (i = 0; i < (len1 + len2); i++)
        product[i] = 0;

    /* 3. Multiply (grade-school) from right to left */
    for (i = len1 - 1; i >= 0; i--)
    {
        digit1 = num1[i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--)
        {
            digit2 = num2[j] - '0';
            sum = product[i + j + 1] + (digit1 * digit2) + carry;
            product[i + j + 1] = sum % 10;
            carry = sum / 10;
        }
        /* Add any leftover carry to the next position */
        product[i + j + 1] += carry;
    }

    /* 4. Print the result (skip leading zeros) */
    print_number(product, len1 + len2);

    /* 5. Free the allocated array */
    free(product);
}

/**
 * main - Entry point: multiplies two positive numbers
 * @argc: The argument count
 * @argv: The argument vector (array of strings)
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    /* 1. Check argument count */
    if (argc != 3)
        print_error_and_exit();

    /* 2. Check if both arguments are digits */
    if (!is_digit(argv[1]) || !is_digit(argv[2]))
        print_error_and_exit();

    /* 3. Multiply and print result */
    multiply(argv[1], argv[2]);

    return (0);
}
