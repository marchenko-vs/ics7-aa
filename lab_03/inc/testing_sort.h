#ifndef _TESTING_SORT_H_
#define _TESTING_SORT_H_

#include <vector>

void test_sort_random_case(const char *const name, 
               void (*sort_function)(std::vector<int>, const std::size_t));
void test_sort_best_case(const char *const name, 
                         void (*sort_function)(std::vector<int>, const std::size_t));
void test_sort_worst_case(const char *const name, 
                          void (*sort_function)(std::vector<int>, const std::size_t));
void print_array(std::vector<int> &array, const std::size_t size);

#endif // _TESTING_SORT_H_
