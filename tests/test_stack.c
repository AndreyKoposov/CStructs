#include <CUnit/Basic.h>

#include "cstructs/stack.h"


void test_push(void) {
    // Arrange
    Stack* s = stack_create();

    // Act
    push(s, 1);
    push(s, 2);
    push(s, 3);

    // Assert
    CU_ASSERT_EQUAL(stack_size(s), 3);
    CU_ASSERT_EQUAL(pop(s), 3);
    CU_ASSERT_EQUAL(pop(s), 2);
    CU_ASSERT_EQUAL(pop(s), 1);
    CU_ASSERT_EQUAL(stack_size(s), 0);

    // Cleanup
    stack_destroy(s);
}

void test_destroy_stack(void) {
    // Arrange
    Stack* s = stack_create();

    // Act
    push(s, 1);
    push(s, 2);
    push(s, 3);

    // Cleanup
    stack_destroy(s);

    // Assert
    CU_ASSERT(1);
}