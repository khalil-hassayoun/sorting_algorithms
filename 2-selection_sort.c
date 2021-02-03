#include "sort.h"

/**
 * selection_sort - sort array of ints using selection sort algorithm
 * @array: Address to first element in array of ints
 * @size: Array's number of elements
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap((array + i), (array + min));
			print_array(array, size);
		}
	}
}
/**
 * swap - interchange 2 integers in stack
 * @first: address to swap @second value into
 * @second: address of value to swaop with value @first
 * Return: Void
 */

void swap(int *first, int *second)
{
	int tmp = *first;
	*first = *second;
	*second = tmp;
}
