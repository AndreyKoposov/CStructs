#include <CUnit/Basic.h>

#include "cstructs/queue.h"


void test_enqueue_1(void) {
    // Arrange
    Queue* q = queue_create();

    // Act
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    // Assert
    CU_ASSERT_EQUAL(queue_size(q), 4);
    CU_ASSERT_EQUAL(dequeue(q), 1);
    CU_ASSERT_EQUAL(dequeue(q), 2);
    CU_ASSERT_EQUAL(dequeue(q), 3);
    CU_ASSERT_EQUAL(dequeue(q), 4);

    // Cleanup
    queue_destroy(q);
}

void test_enqueue_2(void) {
    // Arrange
    Queue* q = queue_create();

    // Act
    enqueue(q, 1);
    int val1 = dequeue(q);
    enqueue(q, 2);
    int val2 = dequeue(q);
    enqueue(q, 3);
    int val3 = dequeue(q);
    enqueue(q, 4);
    int val4 = dequeue(q);
    enqueue(q, 5);
    enqueue(q, 6);
    int val5 = dequeue(q);
    int val6 = dequeue(q);

    // Assert
    CU_ASSERT_EQUAL(queue_size(q), 0);
    CU_ASSERT_EQUAL(val1, 1);
    CU_ASSERT_EQUAL(val2, 2);
    CU_ASSERT_EQUAL(val3, 3);
    CU_ASSERT_EQUAL(val4, 4);
    CU_ASSERT_EQUAL(val5, 5);
    CU_ASSERT_EQUAL(val6, 6);

    // Cleanup
    queue_destroy(q);
}

void test_dequeue(void) {
    // Arrange
    Queue* q = queue_create();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    // Act
    int val1 = dequeue(q);
    int val2 = dequeue(q);
    int val3 = dequeue(q);
    int val4 = dequeue(q);

    // Assert
    CU_ASSERT_EQUAL(queue_size(q), 0);
    CU_ASSERT_EQUAL(val1, 1);
    CU_ASSERT_EQUAL(val2, 2);
    CU_ASSERT_EQUAL(val3, 3);
    CU_ASSERT_EQUAL(val4, 4);

    // Cleanup
    queue_destroy(q);
}

void test_destroy(void) {
    // Arrange
    Queue* q = queue_create();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    // Assert
    CU_ASSERT(1);

    // Cleanup
    queue_destroy(q);
}