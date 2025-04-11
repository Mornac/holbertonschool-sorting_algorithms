#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

<<<<<<< HEAD
			for (k = 0; k < size; k++)
			{
				printf("%d ", array[k]);
			}
			printf("\n");
=======
				print_array(array, size); /* Le checker attendait ca Ingrid */
>>>>>>> origin/main
			}
		}
	}
}
