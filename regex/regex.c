#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a string
 * @str: the string to scan
 * @pattern: the regular expression to match
 *
 * Return: 1 if the pattern matches, 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	/* Base case: if pattern is empty, string must also be empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Handle the case when the pattern has a '*' as the second character */
	if (*(pattern + 1) == '*')
	{
		/* Try matching zero occurrences of the character before '*' */
		if (regex_match(str, pattern + 2))
			return (1);

		/* Try matching one or more occurrences if there's a match */
		while (*str && (*str == *pattern || *pattern == '.'))
		{
			if (regex_match(str + 1, pattern + 2))
				return (1);
			str++;
		}
		return (0);
	}

	/* For normal case, just check if the first characters match and recurse */
	if (*str && (*pattern == '.' || *pattern == *str))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
