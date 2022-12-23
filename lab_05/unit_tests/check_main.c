#include <stdlib.h>
#include <check.h>

Suite *default_suite();
Suite *kmp_suite();

int main()
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    s = default_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    s = kmp_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    if (no_failed == 0)
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}