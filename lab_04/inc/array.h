#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct
{
	int begin_pos;
	int end_pos;
	int busy;
	int *array;
} task_t;

int generate_array(int *const array, const size_t size);
int print_array(const int *const array, const size_t size);
int fill_array(int *const array, const size_t size);
int merge(int *const array, const int begin_pos, 
          const int middle_pos, const int end_pos);
void merge_sort(int *const array, const int begin_pos, const int end_pos);
void *merge_sort_thread(void *arg);
size_t measure_time(const size_t size, const size_t num_of_threads);

#endif // _ARRAY_H_
