#include "sort.h"


/**
 * swap_array - common function to swap two array elements
 * @array: Array to manipulate
 * @s: Size of array
 * @a: index of first element
 * @b: index of second element
 */
void swap_array(int *array, size_t s, int a, int b)
{
	int t = array[a];

	array[a] = array[b];
	array[b] = t;
	print_array(array, s);
}

/**
 * selection_sort - Sort Array with Selection Sort
 * @array: Array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int min, index, counterIndex;

	for (counterIndex = 0; counterIndex < (int)size - 1; counterIndex++)
	{
		for (index = min = counterIndex; index < (int)size; index++)
		{
			if (array[min] > array[index])
				min = index;
		}
		swap_array(array, size, counterIndex, min);
	}
}
