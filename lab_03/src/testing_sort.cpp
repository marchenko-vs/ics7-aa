#include <iostream>
#include <cstdlib>
#include <climits>

#include "sort.h"

#define get_time(time) __asm__ __volatile__("rdtsc" :"=r"(time))

#define N 500
#define NUMBER_OF_ATTEMPTS 1000

void print_array(std::vector<int> &array, const std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
        std::cout << array[i] << ' ';

    std::cout << std::endl;
}

static void fill_array_randomly(std::vector<int> &array, const std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
        array[i] = rand();
}

static void fill_array_forward(std::vector<int> &array, const std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
        array[i] = i;
}

static void fill_array_backward(std::vector<int> &array, const std::size_t size)
{
    for (std::size_t i = 0; i < size; i++)
        array[i] = size - i - 1;
}

void test_sort_random_case(const char *const name, 
               void (*sort_function)(std::vector<int>, const std::size_t))
{
    std::size_t seed;

    get_time(seed);
    srand(seed);

    std::vector<int> array(N, 0);
    std::size_t start_time, end_time, full_time = 0;

    for (std::size_t i = 0; i < NUMBER_OF_ATTEMPTS; i++)
    {
        fill_array_randomly(array, N);

        get_time(start_time);

        sort_function(array, N);

        get_time(end_time);

        full_time += (end_time - start_time);
    }

    std::cout << name << " sort time (default case): " << full_time / 
    NUMBER_OF_ATTEMPTS << std::endl;
}

void test_sort_best_case(const char *const name, 
                         void (*sort_function)(std::vector<int>, const std::size_t))
{
    std::vector<int> array(N, 0);
    std::size_t start_time, end_time, full_time = 0;

    for (std::size_t i = 0; i < NUMBER_OF_ATTEMPTS; i++)
    {
        fill_array_forward(array, N);

        get_time(start_time);

        sort_function(array, N);

        get_time(end_time);

        full_time += (end_time - start_time);
    }

    std::cout << name << " sort time (best case): " << full_time / 
    NUMBER_OF_ATTEMPTS << std::endl;
}

void test_sort_worst_case(const char *const name, 
                          void (*sort_function)(std::vector<int>, const std::size_t))
{
    std::vector<int> array(N, 0);
    std::size_t start_time, end_time, full_time = 0;

    for (std::size_t i = 0; i < NUMBER_OF_ATTEMPTS; i++)
    {
        fill_array_backward(array, N);

        get_time(start_time);

        sort_function(array, N);

        get_time(end_time);

        full_time += (end_time - start_time);
    }

    std::cout << name << " sort time (worst case): " << full_time / 
    NUMBER_OF_ATTEMPTS << std::endl;
}
