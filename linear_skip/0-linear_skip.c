#include "search.h"
#include <stdio.h>

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = NULL, *express = NULL;

    if (!list)
        return (NULL);

    current = list;
    express = list->express;

    /* Traverse express lane to find the range where value could be */
    while (express)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        if (express->n >= value)
            break;
        current = express;
        express = express->express;
    }

    /* Define the range for linear search */
    if (express)
        printf("Value found between indexes [%lu] and [%lu]\n",
               current->index, express->index);
    else
    {
        skiplist_t *temp = current;
        while (temp->next)
            temp = temp->next;
        printf("Value found between indexes [%lu] and [%lu]\n",
               current->index, temp->index);
    }

    /* Perform linear search in the identified range */
    while (current)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return (current);
        if (express && current == express)
            break;
        current = current->next;
    }

    return (NULL);
}
