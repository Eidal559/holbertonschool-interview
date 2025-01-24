#include "holberton.h"
#include <stdlib.h>

/**
 * print_error_and_exit - Prints "Error" and exits with status 98
 *
 * Return: nothing
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
 * print_number - Prints the digits stored in an int array
 * @product: Pointer to the array of integers
 * @size: The size of the array
 *
 * Description: Skips leading zeros. If the result is all zeros, prints "0".
 */
void print_number(int *product, int size)
{
	int i, started = 0;

	for (i = 0; i < size; i++)
	{
		if (!started && product[i] == 0)
			continue;
		started = 1;
		_putchar(product[i] + '0');
	}
	if (!started)
		_putchar('0');
	_putchar('\n');
}

/**
 * multiply - Multiplies two numeric strings and prints the result
 * @num1: First numeric string
 * @num2: Second numeric string
 *
 * Return: nothing
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0;
	int i, j, carry, digit1, digit2, sum;
	int *product;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	product = malloc(sizeof(int) * (len1 + len2));
	if (product == NULL)
		exit(98);

	for (i = 0; i < (len1 + len2); i++)
		product[i] = 0;

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
		product[i + j + 1] += carry;
	}
	print_number(product, len1 + len2);
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
	if (argc != 3)
		print_error_and_exit();
	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		print_error_and_exit();

	multiply(argv[1], argv[2]);
	return (0);
}
