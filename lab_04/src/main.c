#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"

int main(void)
{
	size_t size = 0;
	int tmp;
	printf("Enter size of an array: ");
	if (scanf("%d", &tmp) != 1)
	{
		printf("Error: incorrect data type.\n");
		return -1;
	}
	if (tmp < 1)
	{
		printf("Error: array size has to be positive.\n");
		return -2;
	}
	size = tmp;
	int *array = malloc(sizeof(int) * size);
	if (array == NULL)
	{
		printf("Error: memory can't be allocated.\n");
		return -3;
	}
	printf("Enter elements of the array: ");
	if (fill_array(array, size) == -2)
	{
		printf("Error: incorrect data type.\n");
		free(array);
		return -4;
	}
	merge_sort(array, 0, size);
	printf("Result: ");
	print_array(array, size);
	free(array);
	return 0;
}
