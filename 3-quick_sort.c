#include "sort.h"
/**
 * sort_swap - swaps integers
 * @array: array of ints to sort
 * @size: array size
 * @x: 1st value address
 * @y: 2nd value address
 */
void sort_swap(int *array, size_t size, int *x, int *y)
{
if (*x != *y)
{
*x = *x + *y;
*y = *x - *y;
*x = *x - *y;
print_array((const int *)array, size);
}
}
/**
 * lomuto_partition - array partitioning
 * @array: array of ints
 * @size: array size
 * @low: low index
 * @high: high index
 * Return: size_t
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
int x, y, pivot = array[high];
for (x = y = low; y < high; y++)
if (array[y] < pivot)
sort_swap(array, size, &array[y], &array[x++]);
sort_swap(array, size, &array[x], &array[high]);
return (x);
}
/**
 * quicksort - quicksort
 * @array: integers array
 * @size: array size
 * @low: low index
 * @high: high index
 * Return: Void
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
if (low < high)
{
size_t pos = lomuto_partition(array, size, low, high);
quicksort(array, size, low, pos - 1);
quicksort(array, size, pos + 1, high);
}
}
/**
 * quick_sort - function that sorts an array of ints
 * @array: array of ints
 * @size: size of array
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
if (!array || !size)
return;
quicksort(array, size, 0, size - 1);
}
