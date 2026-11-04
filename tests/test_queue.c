#include <CUnit/Basic.h>

#include "cstructs/queue.h"


void test_queue(void) {
    // Arrange
    Queue* q = create_queue();

    // Act
    queue(q, 1);
    queue(q, 2);
    queue(q, 3);
    queue(q, 4);

    // Assert
    CU_ASSERT_EQUAL(size_queue(q), 4);
    CU_ASSERT_EQUAL(dequeue(q), 1);
    CU_ASSERT_EQUAL(dequeue(q), 2);
    CU_ASSERT_EQUAL(dequeue(q), 3);
    CU_ASSERT_EQUAL(dequeue(q), 4);

    // Cleanup
    destroy_queue(q);
}

void test_dequeue(void) {
    // Arrange
    Queue* q = create_queue();
    queue(q, 1);
    queue(q, 2);
    queue(q, 3);
    queue(q, 4);

    // Act
    int val1 = dequeue(q);
    int val2 = dequeue(q);
    int val3 = dequeue(q);
    int val4 = dequeue(q);

    // Assert
    CU_ASSERT_EQUAL(size_queue(q), 0);
    CU_ASSERT_EQUAL(val1, 1);
    CU_ASSERT_EQUAL(val2, 2);
    CU_ASSERT_EQUAL(val3, 3);
    CU_ASSERT_EQUAL(val4, 4);

    // Cleanup
    destroy_queue(q);
}