#include <stdlib.h>
#include <check.h>

#include "array.h"

START_TEST(test_one_element)
{
    int begin_pos = 0, end_pos = 1 - 1;
    int input_array[1] = {5};
    int correct_array[1] = {5};
    merge_sort(input_array, begin_pos, end_pos);
    ck_assert_int_eq(input_array[0], correct_array[0]);
}
END_TEST

START_TEST(test_sorted_array)
{
    int begin_pos = 0, end_pos = 10 - 1;
    int input_array[10], correct_array[10];
    for (size_t i = 0; i < 10; i++)
    {
        input_array[i] = i - 5;
        correct_array[i] = i - 5;
    }
    merge_sort(input_array, begin_pos, end_pos);
    for (size_t i = 0; i < 10; i++)
        ck_assert_int_eq(input_array[0], correct_array[0]);
}
END_TEST

START_TEST(test_reversed_array)
{
    int begin_pos = 0, end_pos = 10 - 1;
    int input_array[10], correct_array[10];
    for (size_t i = 0; i < 10; i++)
    {
        input_array[i] = 10 - i - 5 - 1;
        correct_array[i] = i - 5;
    }
    merge_sort(input_array, begin_pos, end_pos);
    for (size_t i = 0; i < 10; i++)
        ck_assert_int_eq(input_array[0], correct_array[0]);
}
END_TEST

START_TEST(test_pos_elements)
{
    int begin_pos = 0, end_pos = 10 - 1;
    int input_array[10] = {8, 9, 3, 5, 7, 2, 5, 1, 2, 10};
    int correct_array[10] = {1, 2, 2, 3, 5, 5, 7, 8, 9, 10};
    merge_sort(input_array, begin_pos, end_pos);
    for (size_t i = 0; i < 10; i++)
        ck_assert_int_eq(input_array[0], correct_array[0]);
}
END_TEST

START_TEST(test_neg_elements)
{
    int begin_pos = 0, end_pos = 10 - 1;
    int input_array[10] = {-8, -9, -3, -5, -7, -2, -5, -1, -2, -10};
    int correct_array[10] = {-10, -9, -8, -7, -5, -5, -3, -2, -2, -2};
    merge_sort(input_array, begin_pos, end_pos);
    for (size_t i = 0; i < 10; i++)
        ck_assert_int_eq(input_array[0], correct_array[0]);
}
END_TEST

START_TEST(test_all_elements)
{
    int begin_pos = 0, end_pos = 10 - 1;
    int input_array[10] = {8, -9, 3, -5, 7, -2, 5, 1, -2, 10};
    int correct_array[10] = {-9, -5, -2, -2, 1, 3, 5, 7, 8, 10};
    merge_sort(input_array, begin_pos, end_pos);
    for (size_t i = 0; i < 10; i++)
        ck_assert_int_eq(input_array[0], correct_array[0]);
}
END_TEST

Suite *merge_sort_suite()
{
    Suite *s = suite_create("test merge sort");
    TCase *tc = tcase_create("all tests");
    tcase_add_test(tc, test_one_element);
    tcase_add_test(tc, test_sorted_array);
    tcase_add_test(tc, test_reversed_array);
    tcase_add_test(tc, test_pos_elements);
    tcase_add_test(tc, test_neg_elements);
    tcase_add_test(tc, test_all_elements);
    suite_add_tcase(s, tc);
    return s;
}
