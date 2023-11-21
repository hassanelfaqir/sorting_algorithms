#include "sort.h"

void swap_ints(int *A, int *B)I;
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @A: The first integer to swap.
 * @B: The second integer to swap.
 */
void swap_ints(int *A, int *B)
{
	int tmp;

	tmp = *A;
	*A = *B;
	*B = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *piv, aboveA, below;

	piv = array + right;
	for (aboveA = below = left; below < right; below++)
	{
		if (array[below] < *piv)
		{
			if (aboveA < below)
			{
				swap_ints(array + below, array + aboveA);
				print_array(array, size);
			}
			aboveA++;
		}
	}

	if (array[aboveA] > *piv)
	{
		swap_ints(array + aboveA, piv);
		print_array(array, size);
	}

	return (aboveA);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int par;

	if (right - left > 0)
	{
		par = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, par - 1);
		lomuto_sort(array, size, par + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
