/* 1-insertion_sort_list.c */
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp->prev && temp->n < temp->prev->n)
		{
			prev = temp->prev;
			if (temp->next)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}
	}
}
