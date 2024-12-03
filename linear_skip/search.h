#ifndef SEARCH_H
#define SEARCH_H

#include <stddef.h>

/**
 * struct skiplist_s - Singly linked list with express lane
 * @n: Integer stored in the node
 * @index: Index of the node in the list
 * @next: Pointer to the next node in the list
 * @express: Pointer to the next node in the express lane
 *
 * Description: Singly linked list node structure with an express lane
 * for faster search operations.
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/* Function prototypes */
skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *create_skiplist(int *array, size_t size);
void free_skiplist(skiplist_t *list);

#endif /* SEARCH_H */
