#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined (WIN32) || (_WIN64) // Windows
#include <windows.h>
#define pthread_t DWORD
#define pthread_create(THREAD_ID_PTR, ATTR, ROUTINE, PARAMS) CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ROUTINE,(void*)PARAMS,0,THREAD_ID_PTR)
#define sleep(ms) Sleep(ms)
#else // Linux
#include <pthread.h>
#include <unistd.h>
#endif

#include "array.h"

#define get_time(time) __asm__ __volatile__("rdtsc" :"=A"(time))

int generate_array(int *const array, const size_t size)
{
	if (size < 1)
		return 1;
	srand(clock());
	for (size_t i = 0; i < size; i++)
		array[i] = rand();
	return 0;
}

int print_array(const int *const array, const size_t size)
{
	if (size < 1)
		return 1;
	for (size_t i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}

int fill_array(int *const array, const size_t size)
{
	if (size < 1)
		return -1;
	for (size_t i = 0; i < size; i++)
		if (scanf("%d", &array[i]) != 1)
			return -2;
	return 0;
}

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

size_t measure_time(const size_t size, const size_t num_of_threads)
{
	int *array = (int *)malloc(sizeof(int) * size);
	int begin_pos = 0, last_element = 0;
	generate_array(array, size);
	pthread_t *threads_array = (pthread_t *)malloc(sizeof(pthread_t) * num_of_threads);
	task_t *task_array = (task_t *)malloc(sizeof(task_t) * num_of_threads);
	task_t *task;
	size_t length = size / num_of_threads;
	size_t start_time, end_time;
	// initialize structures
	for (size_t i = 0; i < num_of_threads; i++, begin_pos += length)
	{
		task = &task_array[i];
		task->begin_pos = begin_pos;
		task->end_pos = begin_pos + length - 1;
		if (i == num_of_threads - 1)
			task->end_pos = size - 1;
	}
	// create threads
	for (size_t i = 0; i < num_of_threads; i++)
	{
		task = &task_array[i];
		task->array = array;
		task->busy = 1;
		pthread_create(&threads_array[i], 0, merge_sort_thread, task);
	}
	// wait for all threads_array
	for (size_t i = 0; i < num_of_threads; i++)
		while (task_array[i].busy)
			sleep(50);
	task_t *taskm = &task_array[0];
	get_time(start_time);
	for (size_t i = 1; i < num_of_threads; i++)
	{
		task_t *task = &task_array[i];
		merge(taskm->array, taskm->begin_pos, task->begin_pos - 1, task->end_pos);
	}
    get_time(end_time);
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] < last_element)
			return -1;
		last_element = array[i];
	}
	free(array);
	free(task_array);
	free(threads_array);
	return end_time - start_time;
}
