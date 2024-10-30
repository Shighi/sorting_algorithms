/* File: 103-merge_sort.c */
/* Implementation of merge sort algorithm */
#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: Original array to store merged result
 * @left: Left subarray
 * @right: Right subarray
 * @size: Size of the original array
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (!array || size < 2)
		return;

	mid = size / 2;
	left = malloc(sizeof(int) * mid);
	right = malloc(sizeof(int) * (size - mid));

	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = 0; i < size - mid; i++)
		right[i] = array[i + mid];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);

	free(left);
	free(right);
}
