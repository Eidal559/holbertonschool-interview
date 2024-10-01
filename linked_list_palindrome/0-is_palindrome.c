#include "lists.h"
#include <cstddef>

/**
 * reverse_listint - Reverses a linked list.
 * @head: Pointer to the head of the list.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL, *next = NULL, *current = *head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 * Return: 1 if it is a palindrome, 0 if it is not.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half, *prev_slow = *head;
    listint_t *midnode = NULL; // To handle odd-sized lists
    int result = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1); // An empty list or a single node list is a palindrome

    // Use slow and fast pointers to reach the middle of the list
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    // If the list has an odd number of elements, skip the middle node
    if (fast != NULL)
    {
        midnode = slow;
        slow = slow->next;
    }

    // Reverse the second half of the list
    second_half = slow;
    prev_slow->next = NULL; // Terminate first half
    reverse_listint(&second_half);

    // Compare the first and second halves
    result = compare_lists(*head, second_half);

    // Restore the second half back to the original list
    reverse_listint(&second_half);
    if (midnode != NULL)
    {
        prev_slow->next = midnode;
        midnode->next = second_half;
    }
    else
        prev_slow->next = second_half;

    return (result);
}

/**
 * compare_lists - Compares two linked lists.
 * @head1: Pointer to the head of the first list.
 * @head2: Pointer to the head of the second list.
 * Return: 1 if they are identical, 0 otherwise.
 */
int compare_lists(listint_t *head1, listint_t *head2)
{
    while (head2 != NULL)
    {
        if (head1->n != head2->n)
            return (0);
        head1 = head1->next;
        head2 = head2->next;
    }

    return (1);
}
