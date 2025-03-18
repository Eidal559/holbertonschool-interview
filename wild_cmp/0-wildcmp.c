#include "holberton.h"

/**
 * wildcmp - Compares two strings considering wildcard *
 * @s1: The first string
 * @s2: The second string (may contain *)
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0') /* If * is the last character, it matches everything */
			return (1);
		if (wildcmp(s1, s2 + 1)) /* Try matching 0 characters */
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2)) /* Try matching 1+ characters */
			return (1);
	}

	if (*s1 == *s2) /* If characters match, move both forward */
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
