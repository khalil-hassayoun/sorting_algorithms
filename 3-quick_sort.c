#include "sort.h"

/**
 * quick_sort - sort array of ints in ascending order using quick sort
 * with lomuto partition scheme
 * @array: Start of unordered array
 * @size: length of array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recQsort(array, 0, size - 1, size);
}

/**
 * recQsort - recursive function of quicksort
 * @array: subset array to sort
 * @low: start of partition
 * @high: end of partition
 * @size: lengh of initukl array to print
 *
*/
void recQsort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto(array, low, high, size);
		recQsort(array, low, p - 1, size);
		recQsort(array, p + 1, high, size);
	}
}

/**
 * lomuto - implementation of lomuto partition algorithm
 * @array: where to use lomuto partition
 * @low: Start of lomuto
 * @high: end of lomuto
 * @size: size of array to print it
 * Return: new pivot i
*/
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap((array + i), (array + j));
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap((array + i + 1), (array + high));
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - interchange 2 ints inside array
 * @first: self explanatory
 * @second: Self explanatory
 * Return: void
*/
void swap(int *first, int *second)
{
	int tmp = *first;

	*first = *second;
	*second = tmp;
}
