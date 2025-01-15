#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

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
typedef struct binary_tree_s heap_t;

/* 
 * Prototypes
 * (Add or remove according to the functions you implement.)
 */

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Double pointer to the root node
 * Return: The value of the root node, or 0 on failure
 */
int heap_extract(heap_t **root);

/**
 * binary_tree_print - Prints a binary tree (optional helper)
 * @tree: Pointer to the root node of the tree to print
 *
 * Note: This function is typically provided for debugging/visualization
 *       and is not graded in many projects.
 */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
