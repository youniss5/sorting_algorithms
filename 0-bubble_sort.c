#include "sort.h"
/**
* bubble_sort - function that sorts an array of integers in ascending order.
* @array: integers array
* @size: array size
*/
void bubble_sort(int *array, size_t size)
{
int tem;
size_t j, k;

if (!array || !size)
return;

j = 0;
while (j < size)
{
for (k = 0; k < size - 1; k++)
{
if (array[k] > array[k + 1])
{
tem = array[k];
array[k] = array[k + 1];
array[k + 1] = tem;
print_array(array, size);
}
}
j++;
}
}
