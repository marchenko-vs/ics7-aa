#include <check.h>
#include <cstdlib>

Suite *levenshtein_suite();
Suite *damerau_levenshtein_suite();
Suite *damerau_levenshtein_rec_suite();
Suite *damerau_levenshtein_cache_suite();

int main()
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = levenshtein_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = damerau_levenshtein_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    s = damerau_levenshtein_rec_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = damerau_levenshtein_cache_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}