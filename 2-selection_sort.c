#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"

/**
 *selection_sort - sorts an array of integers in ascending order
 *using the Selection sort algorithm
 *@array: array of integers
 *@size: size of the array
 *Return: array in ascending order
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;
	int temp;
	
	if (array == NULL || size < 2)
		return;
	
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
