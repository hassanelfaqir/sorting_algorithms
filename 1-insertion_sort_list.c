#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @N1: A pointer to the first node to swap.
 * @N2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **N1, listint_t *N2)
{
	(*N1)->next = N2->next;
	if (N2->next != NULL)
		N2->next->prev = *N1;
	N2->prev = (*N1)->prev;
	N2->next = *N1;
	if ((*N1)->prev != NULL)
		(*N1)->prev->next = N2;
	else
		*h = N2;
	(*N1)->prev = N2;
	*N1 = N2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *ins, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		ins = iter->prev;
		while (ins != NULL && iter->n < ins->n)
		{
			swap_nodes(list, &ins, iter);
			print_list((const listint_t *)*list);
		}
	}
}
