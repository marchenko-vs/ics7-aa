int merge(int *const array, const int begin_pos, 
          const int middle_pos, const int end_pos)
{
	int left_size = middle_pos - begin_pos + 1;
	int right_size = end_pos - middle_pos, i, j;
	int *left_array = (int *)malloc(left_size * sizeof(int));
	if (left_array == NULL)
		return -1;
	int *right_array = (int *)malloc(right_size * sizeof(int));
	if (right_array == NULL)
	{
		free(left_array);
		return -1;
	}
	for (i = 0; i < left_size; i++)
		left_array[i] = array[begin_pos + i];
	for (i = 0; i < right_size; i++)
		right_array[i] = array[middle_pos + i + 1];
	int k = begin_pos;
	i = j = 0;
	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}
	while (i < left_size)
		array[k++] = left_array[i++];
	while (j < right_size)
		array[k++] = right_array[j++];
	free(left_array);
	free(right_array);
	return 0;
}
