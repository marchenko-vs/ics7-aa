#include <check.h>

#include <cstdlib>
#include <cstring>

#include "search.h"

START_TEST(test_full_substring)
{
    char text[] = "ababcabcbabcbcbab";
    char substring[] = "ababcabcbabcbcbab";
    int occurrences[10];
    int correct_occurrences[10] = {0};
    int num_of_occur = 0;
    search_default(substring, text, occurrences, &num_of_occur);
    for (int i = 0; i < num_of_occur; i++)
        ck_assert_int_eq(correct_occurrences[i], occurrences[i]);
}
END_TEST

START_TEST(test_no_substring)
{
    char text[] = "ababcabcbabcbcbab";
    char substring[] = "q";
    int occurrences[10];
    int correct_occurrences[10] = {-1};
    int num_of_occur = 0;
    search_default(substring, text, occurrences, &num_of_occur);
    for (int i = 0; i < num_of_occur; i++)
        ck_assert_int_eq(correct_occurrences[i], occurrences[i]);
}
END_TEST

START_TEST(test_several_substrings)
{
    char text[] = "ababcabcbabcbcbab";
    char substring[] = "ab";
    int occurrences[10];
    int correct_occurrences[10] = {0, 2, 5, 9, 15};
    int num_of_occur = 0;
    search_default(substring, text, occurrences, &num_of_occur);
    for (int i = 0; i < num_of_occur; i++)
        ck_assert_int_eq(correct_occurrences[i], occurrences[i]);
}
END_TEST

START_TEST(test_overlapping_substrings)
{
    char text[] = "abababababababababab";
    char substring[] = "aba";
    int occurrences[10];
    int correct_occurrences[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int num_of_occur = 0;
    search_default(substring, text, occurrences, &num_of_occur);
    for (int i = 0; i < num_of_occur; i++)
        ck_assert_int_eq(correct_occurrences[i], occurrences[i]);
}
END_TEST

START_TEST(test_default_case)
{
    char text[] = "just a simple str1ng just a simple string";
    char substring[] = "just a simple string";
    int occurrences[10];
    int correct_occurrences[10] = {21};
    int num_of_occur = 0;
    search_default(substring, text, occurrences, &num_of_occur);
    for (int i = 0; i < num_of_occur; i++)
        ck_assert_int_eq(correct_occurrences[i], occurrences[i]);
}
END_TEST

Suite *default_suite()
{
    Suite *s = suite_create("test default algorithm");
    TCase *tc = tcase_create("all tests");
    tcase_add_test(tc, test_full_substring);
    tcase_add_test(tc, test_no_substring);
    tcase_add_test(tc, test_several_substrings);
    tcase_add_test(tc, test_overlapping_substrings);
    tcase_add_test(tc, test_default_case);
    suite_add_tcase(s, tc);
    return s;
}
