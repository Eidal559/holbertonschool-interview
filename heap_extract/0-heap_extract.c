#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size (number of nodes) of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The total number of nodes, or 0 on failure
 */
static size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_l, size_r;

	if (!tree)
		return (0);

	size_l = binary_tree_size(tree->left);
	size_r = binary_tree_size(tree->right);
	return (size_l + size_r + 1);
}

/**
 * get_last_node - Returns the last node in level-order traversal
 * @root: Pointer to the root node of the heap
 * Return: Pointer to the last node, or NULL on failure
 *
 * We do a simple BFS using an array as a queue (sized by total node count).
 */
static heap_t *get_last_node(heap_t *root)
{
	heap_t **queue;
	size_t front = 0, back = 0, size;
	heap_t *current = NULL;

	if (!root)
		return (NULL);

	/* Allocate an array-based queue big enough for all nodes */
	size = binary_tree_size(root);
	queue = malloc(sizeof(heap_t *) * size);
	if (!queue)
		return (NULL);

	queue[back++] = root;
	while (front < back)
	{
		current = queue[front++];
		if (current->left)
			queue[back++] = current->left;
		if (current->right)
			queue[back++] = current->right;
	}
	/* current ends up being the last node visited in level order */
	free(queue);
	return (current);
}

/**
 * heapify_down - Rebalances (sifts down) a max heap from the given node
 * @node: Pointer to the node to begin sifting down
 *
 * Compare the node with its children; if a child is bigger,
 * swap and move down.
 */
static void heapify_down(heap_t *node)
{
	heap_t *largest;
	int temp;

	if (!node)
		return;

	while (1)
	{
		largest = node;
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest == node)
			break;

		/* Swap values with the largest child */
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;
		node = largest;
	}
}

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value at the root, or 0 on failure
 *
 * Steps:
 * 1) If empty, return 0.
 * 2) Save root value.
 * 3) Find the last node in level order.
 * 4) If there's only one node, remove it entirely.
 * 5) Otherwise, copy last node's value into root, unlink the last node,
 *    free that node, then sift down from the root.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last, *parent;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	/* If there's only one node, just remove it */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Find last node in level order */
	last = get_last_node(*root);
	if (!last)
		return (0);

	/* Move last node's value into root, then detach last node from its parent */
	(*root)->n = last->n;
	parent = last->parent;
	if (parent->right == last)
		parent->right = NULL;
	else
		parent->left = NULL;
	free(last);

	/* Re-heapify from the root */
	heapify_down(*root);

	return (value);
}
