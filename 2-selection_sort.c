#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @A: The first integer to swap.
 * @B: The second integer to swapi.
 */
void swap_ints(int *A, int *B)
{
	int tmp;

	tmp = *A;
	*A = *B;
	*B = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *m;
	size_t K, j;

	if (array == NULL || size < 2)
		return;

	for (K = 0; K < size - 1; K++)
	{
		m = array + i;
		for (j = i + 1; j < size; j++)
			m = (array[j] < *m) ? (array + j) : m;

		if ((array + K) != m)
		{
			swap_ints(array + K, m);
			print_array(array, size);
		}
	}
}
