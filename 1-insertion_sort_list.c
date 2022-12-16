#include "sort.h"

/**
 * swap_list - Swap two nodes
 * @nodeA: First node to swap
 * @nodeB: Second Node to swap
 */
void swap_list(listint_t *nodeA, listint_t *nodeB)
{
	listint_t *placeholder;

	placeholder = nodeA->next;
	nodeA->next = nodeB->next;
	nodeB->next = placeholder;

	if (nodeA->next)
		nodeA->next->prev = nodeA;
	if (nodeB->next)
		nodeB->next->prev = nodeB;
	placeholder = nodeA->prev;
	nodeA->prev = nodeB->prev;
	nodeB->prev = placeholder;

	if (nodeA->prev)
		nodeA->prev->next = nodeA;
	if (nodeB->prev)
		nodeB->prev->next = nodeB;
	while (placeholder->prev)
		placeholder = placeholder->prev;
	print_list(placeholder);
}

/**
 * insertion_sort_list - Sort a list with Insertion_Sort
 * @list: List to sort;
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *head, *sub_index;

	if (!(list) || !(*list))
		return;
	head = *list;
	while (head->prev)
		head = head->prev;
	for (index = head; index;
	     index = (sub_index ? sub_index->next : index->next))
	{ /* Loop from head to tail */
		for (sub_index = index; sub_index; sub_index = sub_index->prev)
		{
			if (sub_index->prev && sub_index->n < sub_index->prev->n)
				swap_list(sub_index, sub_index->prev);
			else
				break;
		}
	}
	while (head->prev)
		head = head->prev;
	*list = head;
}
