#include <cstdlib>
#include <vector>
#include <check.h>

#include "matrix.h"

using namespace matrix;

START_TEST(test_one_element)
{
    matrix_t matrix_1, matrix_2, matrix_res;
    matrix_1.rows = matrix_1.columns = matrix_2.rows = matrix_2.columns = 1;
    std::vector<int> row(1, 5);
    matrix_1.elements.push_back(row);
    row[0] = -9;
    matrix_2.elements.push_back(row);
    default_mul(matrix_1, matrix_2, matrix_res);
    ck_assert_int_eq(matrix_res.elements[0][0], -45);
}
END_TEST

START_TEST(test_square_matrix)
{
    matrix_t matrix_1, matrix_2, matrix_res;
    matrix_1.rows = matrix_1.columns = matrix_2.rows = matrix_2.columns = 5;
    int k = 1;
    for (std::size_t i = 0; i < matrix_1.rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < matrix_1.columns; j++)
            row.push_back(k++);
        matrix_1.elements.push_back(row);
        matrix_2.elements.push_back(row);
    }
    int correct[5][5] = {{215, 230, 245, 260, 275},
                         {490, 530, 570, 610, 650},
                         {765, 830, 895, 960, 1025},
                         {1040, 1130, 1220, 1310, 1400},
                         {1315, 1430, 1545, 1660, 1775}};
    default_mul(matrix_1, matrix_2, matrix_res);
    for (std::size_t i = 0; i < matrix_res.rows; i++)
    {
        for (std::size_t j = 0; j < matrix_res.columns; j++)
            ck_assert_int_eq(matrix_res.elements[i][j], correct[i][j]);
    }
}
END_TEST

START_TEST(test_rows_lt_columns_matrix)
{
    matrix_t matrix_1, matrix_2, matrix_res;
    matrix_1.rows = 4;
    matrix_1.columns = 5;
    matrix_2.rows = 5;
    matrix_2.columns = 6;
    int k = 1;
    for (std::size_t i = 0; i < matrix_1.rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < matrix_1.columns; j++)
            row.push_back(k++);
        matrix_1.elements.push_back(row);
    }
    k = 1;
    for (std::size_t i = 0; i < matrix_2.rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < matrix_2.columns; j++)
            row.push_back(k++);
        matrix_2.elements.push_back(row);
    }
    int correct[4][6] = {{255, 270, 285, 300, 315, 330},
                         {580, 620, 660, 700, 740, 780},
                         {905, 970, 1035, 1100, 1165, 1230},
                         {1230, 1320, 1410, 1500, 1590, 1680}};
    default_mul(matrix_1, matrix_2, matrix_res);
    for (std::size_t i = 0; i < matrix_res.rows; i++)
    {
        for (std::size_t j = 0; j < matrix_res.columns; j++)
            ck_assert_int_eq(matrix_res.elements[i][j], correct[i][j]);
    }
}
END_TEST

START_TEST(test_rows_gt_columns_matrix)
{
    matrix_t matrix_1, matrix_2, matrix_res;
    matrix_1.rows = 6;
    matrix_1.columns = 5;
    matrix_2.rows = 5;
    matrix_2.columns = 4;
    int k = 1;
    for (std::size_t i = 0; i < matrix_1.rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < matrix_1.columns; j++)
            row.push_back(k++);
        matrix_1.elements.push_back(row);
    }
    k = 1;
    for (std::size_t i = 0; i < matrix_2.rows; i++)
    {
        std::vector<int> row;
        for (std::size_t j = 0; j < matrix_2.columns; j++)
            row.push_back(k++);
        matrix_2.elements.push_back(row);
    }
    int correct[6][4] = {{175, 190, 205, 220},
                         {400, 440, 480, 520},
                         {625, 690, 755, 820},
                         {850, 940, 1030, 1120},
                         {1075, 1190, 1305, 1420},
                         {1300, 1440, 1580, 1720}};
    default_mul(matrix_1, matrix_2, matrix_res);
    for (std::size_t i = 0; i < matrix_res.rows; i++)
    {
        for (std::size_t j = 0; j < matrix_res.columns; j++)
            ck_assert_int_eq(matrix_res.elements[i][j], correct[i][j]);
    }
}
END_TEST

Suite *default_mul_suite()
{
    Suite *s = suite_create("test default multiplication");
    TCase *tc = tcase_create("all tests");
    tcase_add_test(tc, test_one_element);
    tcase_add_test(tc, test_square_matrix);
    tcase_add_test(tc, test_rows_lt_columns_matrix);
    tcase_add_test(tc, test_rows_gt_columns_matrix);
    suite_add_tcase(s, tc);
    return s;
}
