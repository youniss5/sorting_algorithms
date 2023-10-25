#include "sort.h"
/**
 * sort_swap - function that swaps 2 nodes.
 * @x: 1st node adress
 * @y: 2nd node address
 * Return: Void
 */
void sort_swap(listint_t *x, listint_t *y)
{
if (x->prev)
x->prev->next = y;
if (y->next)
y->next->prev = x;
x->next = y->next;
y->prev = x->prev;
x->prev = y;
y->next = x;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of ints.
 * @list: adress of head node pointer
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *j, *k;

if (!list || !*list || !(*list)->next)
return;
j = (*list)->next;
while (j)
{
k = j;
j = j->next;
while (k && k->prev)
{
if (k->prev->n > k->n)
{
sort_swap(k->prev, k);
if (!k->prev)
*list = k;
print_list((const listint_t *)*list);
}
else
k = k->prev;
}
}
}
