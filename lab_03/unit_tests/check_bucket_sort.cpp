#include <cstdlib>
#include <vector>
#include <check.h>

#include "sort.h"

START_TEST(test_one_element)
{
    std::vector<int> correct_array{9};
    std::vector<int> input_array{9};

    bucket_sort(input_array, input_array.size());

    ck_assert_int_eq(correct_array[0], input_array[0]);
}
END_TEST

START_TEST(test_worst_case)
{
    std::vector<int> correct_array;
    std::vector<int> input_array;

    for (std::size_t i = 0; i < input_array.size(); i++)
    {
        correct_array.push_back(i);
        input_array.push_back(input_array.size() - i - 1);
    }

    bucket_sort(input_array, input_array.size());

    for (std::size_t i = 0; i < input_array.size(); i++)
        ck_assert_int_eq(correct_array[i], input_array[i]);
}
END_TEST

START_TEST(test_best_case)
{
    std::vector<int> correct_array;
    std::vector<int> input_array;

    for (std::size_t i = 0; i < input_array.size(); i++)
    {
        correct_array.push_back(i);
        input_array.push_back(i);
    }

    bucket_sort(input_array, input_array.size());

    for (std::size_t i = 0; i < input_array.size(); i++)
        ck_assert_int_eq(correct_array[i], input_array[i]);
}
END_TEST

START_TEST(test_random_case)
{
    std::vector<int> correct_array{-76, -7, -5, -3, 0, 2, 9, 12, 39, 109};
    std::vector<int> input_array{39, 12, -3, -7, 0, 2, -5, 9, 109, -76};

    bucket_sort(input_array, input_array.size());

    for (std::size_t i = 0; i < input_array.size(); i++)
        ck_assert_int_eq(correct_array[i], input_array[i]);
}
END_TEST

Suite *bucket_sort_suite()
{
    Suite *s = suite_create("test bucket sort");

    TCase *tc = tcase_create("all tests");

    tcase_add_test(tc, test_one_element);
    tcase_add_test(tc, test_worst_case);
    tcase_add_test(tc, test_best_case);
    tcase_add_test(tc, test_random_case);

    suite_add_tcase(s, tc);

    return s;
}
