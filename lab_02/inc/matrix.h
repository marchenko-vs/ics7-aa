#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstddef>
#include <vector>

namespace matrix
{
    typedef struct
    {
        std::vector<std::vector<int>> elements;
        std::size_t rows;
        std::size_t columns;
    } matrix_t;

    int get_size(matrix_t &matrix);
    int scan(matrix_t &matrix);
    void print(const matrix_t &matrix);
    void free(matrix_t &matrix);
    int default_mul(const matrix_t &matrix_1, const matrix_t &matrix_2, matrix_t &matrix_res);
    int winograd_mul(const matrix_t &matrix_1, const matrix_t &matrix_2, matrix_t &matrix_res);
    int optimized_winograd_mul(const matrix_t &matrix_1, const matrix_t &matrix_2, matrix_t &matrix_res);
}

#endif // _MATRIX_H_
