#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			if (temp->prev->prev)
				temp->prev->prev->next = temp;
			if (temp->next)
				temp->next->prev = temp->prev;

			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;

			if (!temp->prev)
				*list = temp;

			print_list(*list);
		}
	}
}
