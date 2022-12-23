#include <vector>
#include <cstddef>
#include <iostream>
#include <fstream>

#include "matrix.h"
#include "analysis.h"

#define get_time(time) __asm__ __volatile__("rdtsc" \
                                            : "=r"(time))

#define NUMBER_OF_ATTEMPTS 2

static void fill_matrix_randomly(matrix::matrix_t &matrix)
{
    for (std::size_t i = 0; i < matrix.rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < matrix.columns; j++)
            row.push_back(rand());
        matrix.elements.push_back(row);
    }
}

static std::size_t test(const std::size_t m, const std::size_t n, const std::size_t l,
                        int (*mul_function)(const matrix::matrix_t &, const matrix::matrix_t &, matrix::matrix_t &))
{
    std::size_t seed;
    get_time(seed);
    srand(seed);
    matrix::matrix_t matrix_1;
    matrix::matrix_t matrix_2;
    matrix::matrix_t matrix_res;
    matrix_1.rows = m;
    matrix_1.columns = matrix_2.rows = n;
    matrix_2.columns = l;
    std::size_t start_time, end_time, full_time = 0;
    for (std::size_t i = 0; i < NUMBER_OF_ATTEMPTS; i++)
    {
        fill_matrix_randomly(matrix_1);
        fill_matrix_randomly(matrix_2);
        get_time(start_time);
        mul_function(matrix_1, matrix_2, matrix_res);
        get_time(end_time);
        full_time += (end_time - start_time);
    }
    return full_time / NUMBER_OF_ATTEMPTS;
}

void test_full()
{
    std::ofstream f;
    f.open("data_1.csv");
    f << "Elements" << ';' << "Classic" << ';' << "Winograd" << ';' << "Optimized Winograd" << std::endl;
    std::size_t time_1, time_2, time_3;
    std::size_t n = 2;
    for (std::size_t i = 0; i < 20; i++)
    {
        time_1 = test(n, n, n, matrix::default_mul);
        time_2 = test(n, n, n, matrix::winograd_mul);
        time_3 = test(n, n, n, matrix::optimized_winograd_mul);
        f << n * n << ';' << time_1 << ';' << time_2 << ';' << time_3 << std::endl;
        n++;
    }
    f.close();
}
