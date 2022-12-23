void *merge_sort_thread(void *arg)
{
	task_t *task = (task_t *)arg;
	int begin_pos = task->begin_pos, end_pos = task->end_pos;
	int middle_pos = begin_pos + (end_pos - begin_pos) / 2;
	if (begin_pos < end_pos)
	{
		merge_sort(task->array, begin_pos, middle_pos);
		merge_sort(task->array, middle_pos + 1, end_pos);
		merge(task->array, begin_pos, middle_pos, end_pos);
	}
	task->busy = 0;
	return NULL;
}
