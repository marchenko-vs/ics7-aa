#include <check.h>
#include <string>
#include <cstdlib>
#include <cstring>

#include "levenshtein.h"

START_TEST(test_same_strings)
{
    std::string str_1 = "mercedes";
    std::string str_2 = "mercedes";
    int result = levenshtein(str_1, str_1.size(), str_2, str_2.size());
    ck_assert_int_eq(0, result);
}
END_TEST

START_TEST(test_change)
{
    std::string str_1 = "mercedes";
    std::string str_2 = "meycedes";
    int result = levenshtein(str_1, str_1.size(), str_2, str_2.size());
    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test_delete)
{
    std::string str_1 = "mercedqes";
    std::string str_2 = "mercedes";
    int result = levenshtein(str_1, str_1.size(), str_2, str_2.size());
    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test_insert)
{
    std::string str_1 = "mercees";
    std::string str_2 = "mercedes";
    int result = levenshtein(str_1, str_1.size(), str_2, str_2.size());
    ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(test_delete_and_change)
{
    std::string str_1 = "aqstria";
    std::string str_2 = "australia";
    int result = levenshtein(str_1, str_1.size(), str_2, str_2.size());
    ck_assert_int_eq(3, result);
}
END_TEST

Suite *levenshtein_suite()
{
    Suite *s = suite_create("test levenshtein");
    TCase *tc = tcase_create("all tests");
    tcase_add_test(tc, test_same_strings);
    tcase_add_test(tc, test_change);
    tcase_add_test(tc, test_delete);
    tcase_add_test(tc, test_insert);
    tcase_add_test(tc, test_delete_and_change);
    suite_add_tcase(s, tc);
    return s;
}
