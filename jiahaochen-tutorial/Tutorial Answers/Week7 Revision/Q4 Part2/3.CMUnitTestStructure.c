struct CMUnitTest {
    const char *name;                /* name of test */
    CMUnitTestFunction test_func;    /* function pointer for test function */
    CMFixtureFunction setup_func;    /* fp for setup function */
    CMFixtureFunction teardown_func; /* fp for teardown function */
    void *initial_state;             /* private data for test */
};


#define 	cmocka_unit_test(f)   { #f, f, NULL, NULL, NULL }
#define 	cmocka_unit_test_setup(f, setup)   { #f, f, setup, NULL, NULL }
#define 	cmocka_unit_test_teardown(f, teardown)   { #f, f, NULL, teardown, NULL }
#define 	cmocka_unit_test_setup_teardown(f, setup, teardown)   { #f, f, setup, teardown, NULL }
#define 	cmocka_unit_test_prestate(f, state)   { #f, f, NULL, NULL, state }
#define 	cmocka_unit_test_prestate_setup_teardown(f, setup, teardown, state)   { #f, f, setup, teardown, state }


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(int_test_success, setup, teardown),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

