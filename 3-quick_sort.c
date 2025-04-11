#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: index of the pivot after partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j && array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high && array[i] != array[high])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - recursive function to sort subarrays
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: total size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array using Quick Sort algorithm
 * @array: array to sort
 * @size: number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
