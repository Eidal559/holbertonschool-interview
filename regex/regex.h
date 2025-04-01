#ifndef REGEX_H
#define REGEX_H

/**
 * regex_match - Checks if a pattern matches a string
 * @str: the string to scan
 * @pattern: the regular expression to match
 *
 * Return: 1 if the pattern matches, 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
