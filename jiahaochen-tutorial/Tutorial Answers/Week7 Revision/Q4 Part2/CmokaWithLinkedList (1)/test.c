// gcc test.c LinkedList.c -L . -l cmocka-static
// gcc -fsanitize=address test.c LinkedList.c -L . -l cmocka-static
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include "cmocka.h"

#include "LinkedList.h"


static int create_list(void **state) {
    node* head = list_init(0);
    *state = (void*) head;
    return 0;
  
}

static int free_list(void **state) {
    node* head = (node*) *state;
    list_free(head);
    return 0;

}

static void test_list_add(void **state) {
    node* head = (node*) *state;
    list_add(head, 1);
    assert_int_equal(1, list_next(head)->v);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(test_list_add, create_list, free_list)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

