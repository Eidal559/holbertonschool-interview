#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/* Function prototypes */
int binary_tree_is_avl(const binary_tree_t *tree);

/* Helper functions */
int height(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);
int is_avl_helper(const binary_tree_t *tree);

/* Provided printing function */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
