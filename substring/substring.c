#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * find_substring - Finds all possible substrings containing a concatenation of all words
 * @s: String to scan
 * @words: Array of words all substrings must be a concatenation arrangement of
 * @nb_words: Number of elements in the array words
 * @n: Pointer to store the number of elements in the returned array
 * 
 * Return: An allocated array, storing each index in s at which a substring was found
 *         If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    if (!s || !words || !nb_words || !n)
        return NULL;

    *n = 0;
    int s_len = strlen(s);

    /* Since all words are the same length, we can determine it from the first word */
    int word_len = strlen(words[0]);

    /* The total length of all words concatenated */
    int total_substr_len = word_len * nb_words;

    /* If the string is shorter than all words concatenated, return NULL */
    if (s_len < total_substr_len)
        return NULL;

    /* Allocate memory for indices - at most, we can have (s_len - total_substr_len + 1) matches */
    int max_matches = s_len - total_substr_len + 1;
    int *indices = malloc(max_matches * sizeof(int));
    if (!indices)
        return NULL;

    /* For each possible starting position in the main string */
    for (int i = 0; i <= s_len - total_substr_len; i++)
    {
        /* Create a copy of words array to mark which ones we've found */
        int *found = calloc(nb_words, sizeof(int));
        if (!found)
        {
            free(indices);
            return NULL;
        }

        int words_found = 0;
        int valid = 1;
        
        /* Check each possible word position in the current substring window */
        for (int j = 0; j < nb_words && valid; j++)
        {
            /* Extract the current word-sized chunk from the string */
            char temp[word_len + 1];
            strncpy(temp, s + i + j * word_len, word_len);
            temp[word_len] = '\0';
            
            int word_found = 0;

            /* Try to match this chunk with each word */
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

            /* If current chunk doesn't match any word, this substring is invalid */
            if (!word_found)
                valid = 0;
        }

        free(found);
        
        /* If we found all words in this substring, add the index to our result */
        if (valid && words_found == nb_words)
            indices[(*n)++] = i;
    }

    /* If no indices found, free the array and return NULL */
    if (*n == 0)
    {
        free(indices);
        return NULL;
    }

    /* Resize the array to the actual number of indices found */
    int *result = realloc(indices, (*n) * sizeof(int));
    return result ? result : indices;
}
