#include <cstdlib>
#include <cstdio>

#include "matrix.h"
#include "analysis.h"

int main()
{
    setbuf(stdout, NULL);
    int option = 0, rc = 0;
    matrix::matrix_t matrix_1, matrix_2, matrix_res;
    printf("Enter size of matrix #1: ");
    if ((rc = matrix::get_size(matrix_1)) == 1)
    {
        printf("Error: incorrect data type.\n");
        return 1;
    }
    else if (rc == 2)
    {
        printf("Error: number of rows and columns should be positive integers.\n");
        return 2;
    }
    printf("Enter size of matrix #2: ");
    if ((rc = matrix::get_size(matrix_2)) == 1)
    {
        printf("Error: incorrect data type.\n");
        return 1;
    }
    else if (rc == 2)
    {
        printf("Error: number of rows and columns should be positive integers.\n");
        return 2;
    }
    printf("Enter elements of matrix #1: ");
    if (matrix::scan(matrix_1) == 1)
    {
        printf("Error: incorrect data type.\n");
        return 1;
    }
    printf("Enter elements of matrix #2: ");
    if (matrix::scan(matrix_2) == 1)
    {
        printf("Error: incorrect data type.\n");
        return 1;
    }
    printf("1. Default algorithm.\n2. Winograd algorithm.\n3. Optimized Winograd algorithm.\n");
    if (scanf("%d", &option) != 1)
    {
        printf("Error: incorrect data type.\n");
        return 1;
    }
    switch (option)
    {
    case 1:
        matrix::default_mul(matrix_1, matrix_2, matrix_res);
        break;
    case 2:
        matrix::winograd_mul(matrix_1, matrix_2, matrix_res);
        break;
    case 3:
        matrix::optimized_winograd_mul(matrix_1, matrix_2, matrix_res);
        break;
    default:
        printf("Error: option should be from 1 to 3.\n");
        return 3;
    }
    printf("Result matrix:\n");
    matrix::print(matrix_res);
    return 0;
}
