#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned long integer is a palindrome
 * @n: the number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, original = n, remainder;

    // Reverse the number
    while (n != 0)
    {
        remainder = n % 10;       // Get the last digit
        reversed = reversed * 10 + remainder;  // Append it to reversed
        n /= 10;                  // Remove the last digit
    }

    // Check if reversed number is the same as the original
    if (original == reversed)
        return 1;
    else
        return 0;
}
