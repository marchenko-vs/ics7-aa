#include <stdlib.h>

#include <check.h>

Suite *default_mul_suite();
Suite *winograd_mul_suite();
Suite *optimized_winograd_mul_suite();

int main()
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = default_mul_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = winograd_mul_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = optimized_winograd_mul_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}