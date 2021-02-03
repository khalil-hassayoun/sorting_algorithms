#include "sort.h"

/**
 * swap_nodes - Interchange node links in doubly linked list
 * @list: curent head of list
 * @a: left node
 * @b: right node
 * Return: void
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		(a->prev)->next = b;
	else
		*list = b, b->prev = NULL;

	if (b->next)
		(b->next)->prev = a;

	b->prev = a->prev;
	a->prev = b;
	a->next = b->next;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: address of head pointer of a doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || *list == NULL)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i->prev;
		/*comparar actual con anteriores*/
		while (j && i->n < j->n)
		/*Hacer swap entre anterior y nuevo*/
		{
			swap_nodes(list, j, i);
			j = i->prev;
			print_list(*list);
		}
		i = i->next;
	}
}
