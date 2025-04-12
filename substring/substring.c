#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_valid_combination - Checks if current window contains all required words
 * @s: The source string
 * @i: Starting index in source string
 * @words: Array of words to find
 * @nb_words: Number of words in the array
 * @word_len: Length of each word
 *
 * Return: 1 if valid combination found, 0 otherwise
 */
static int is_valid_combination(char const *s, int i, char const **words,
		int nb_words, int word_len)
{
	int *found = calloc(nb_words, sizeof(int));

	if (!found)
		return (0);

	int words_found = 0;
	int valid = 1;

	for (int j = 0; j < nb_words && valid; j++)
	{
		char temp[word_len + 1];

		strncpy(temp, s + i + j * word_len, word_len);
		temp[word_len] = '\0';

		int word_found = 0;

		for (int k = 0; k < nb_words; k++)
		{
			if (!found[k] && strcmp(temp, words[k]) == 0)
			{
				found[k] = 1;
				words_found++;
				word_found = 1;
				break;
			}
		}

		if (!word_found)
			valid = 0;
	}

	free(found);
	return (valid && words_found == nb_words);
}

/**
 * find_substring - Finds all possible substrings containing a list of words
 * @s: String to scan
 * @words: Array of words all substrings must be a concatenation of
 * @nb_words: Number of elements in the array words
 * @n: Pointer to store the number of elements in the returned array
 *
 * Return: An allocated array with indices where substrings were found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (!s || !words || !nb_words || !n)
		return (NULL);

	*n = 0;
	int s_len = strlen(s);
	int word_len = strlen(words[0]);
	int total_substr_len = word_len * nb_words;

	if (s_len < total_substr_len)
		return (NULL);

	int max_matches = s_len - total_substr_len + 1;
	int *indices = malloc(max_matches * sizeof(int));

	if (!indices)
		return (NULL);

	for (int i = 0; i <= s_len - total_substr_len; i++)
	{
		if (is_valid_combination(s, i, words, nb_words, word_len))
			indices[(*n)++] = i;
	}

	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}

	int *result = realloc(indices, (*n) * sizeof(int));

	return (result ? result : indices);
}
