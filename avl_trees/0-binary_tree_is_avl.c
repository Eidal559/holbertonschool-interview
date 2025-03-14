#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is NULL.
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a valid Binary Search Tree (BST).
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum allowed value for nodes.
 * @max: The maximum allowed value for nodes.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);
	balance_factor = left_height - right_height;

	if (balance_factor > 1 || balance_factor < -1)
		return (0);

	return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree));
}
