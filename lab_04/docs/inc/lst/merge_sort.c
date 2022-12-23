void merge_sort(int *const array, const int begin_pos, const int end_pos)
{
	int middle_pos = begin_pos + (end_pos - begin_pos) / 2;
	if (begin_pos < end_pos)
	{
		merge_sort(array, begin_pos, middle_pos);
		merge_sort(array, middle_pos + 1, end_pos);
		merge(array, begin_pos, middle_pos, end_pos);
	}
}
