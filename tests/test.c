#include <CUnit/Basic.h>

#include "test_queue.h"
#include "test_stack.h"

CU_ErrorCode cleanup() {
    CU_cleanup_registry();
    return CU_get_error();
}

int main() {
    CU_pSuite queueS = NULL;
    CU_pSuite stackS = NULL;

    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    queueS = CU_add_suite("Queue", NULL, NULL);
    if (queueS == NULL) cleanup();

    stackS = CU_add_suite("Stack", NULL, NULL);
    if (stackS == NULL) cleanup();

    if (!CU_add_test(queueS, "enqueue", test_enqueue_1)) cleanup();
    if (!CU_add_test(queueS, "enqueue", test_enqueue_2)) cleanup();
    if (!CU_add_test(queueS, "dequeue", test_dequeue)) cleanup();
    if (!CU_add_test(queueS, "destroy", test_destroy_queue)) cleanup();

    if (!CU_add_test(stackS, "push", test_push)) cleanup();
    if (!CU_add_test(stackS, "destroy", test_destroy_stack)) cleanup();

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    cleanup();
}