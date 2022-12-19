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

	if (a == b)
		return;
	array[a] = array[b];
	array[b] = t;
	print_array(array, s);
}

void quick_sort_r(int *, size_t, const int *, const size_t);

/**
 * quick_sort - Sort array via Quick Sort
 * @array: pointer to head of array
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_r(array, size, array, size);
}
/**
 * quick_sort_r - Recursive helper for quick sort
 * @array: head of sub array
 * @size: size of sub array
 * @a: head of full array
 * @f: size of full array
 */
void quick_sort_r(int *array, size_t size, const int *a, const size_t f)
{
	int l_index, pivot_value, i;

	printf("Size: %li\n", size);
	if (size <= 1)
		return;
	if (size == 2)
	{
		if (array[0] > array[1])
			swap_array(array, size, 0, 1);
		return;
	}
	pivot_value = array[size - 1];

	i = -1;
	for (l_index = 0; l_index < (int)size - 1; l_index++)
	{
		if (array[l_index] <= pivot_value)
		{
			i++;
			swap_array(a, f,
				   (array - a) + i, (array - a) + l_index);
		}
	}
	i++;
	swap_array(a, f, (array - a) + i, (array - a) + (size - 1));
	/* Split around i */
	if (i > 1)
		quick_sort_r(array, i, a, f);
	if (i < (int) size && i >= 0)
		quick_sort_r((array + i + 1), size - (i + 1), a, f);
}
