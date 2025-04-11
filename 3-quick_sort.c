#include "sort.h"

/**
 * partition_array - partitions the array using a pivot (Lomuto)
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 * Return: the index where the pivot ends up
 */
int partition_array(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - recursive helper for quick_sort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: total size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition_array(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using the Quick Sort algorithm
 * @array: the array to sort
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
