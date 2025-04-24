#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "../include/queue.h"

Vehicle* create_test_vehicle(const char* id, const char* destination)
{
    return vehicle_create(id, destination);
}

START_TEST(test_queue_creation)
{
    Queue* queue = queue_create();
    ck_assert_ptr_nonnull(queue);
    ck_assert_int_eq(queue->size, 0);
    queue_destroy(queue);
}
END_TEST

START_TEST(test_queue_push)
{
    Queue* queue = queue_create();
    Vehicle* vehicle1 = create_test_vehicle("vehicle1", "north");

    queue_push(queue, vehicle1, "north");
    ck_assert_int_eq(queue->size, 1);
    ck_assert_ptr_nonnull(queue->front);
    ck_assert_str_eq(queue->front->data->id, "vehicle1");

    queue_destroy(queue);
}
END_TEST

START_TEST(test_queue_pop)
{
    Queue* queue = queue_create();
    Vehicle* vehicle1 = create_test_vehicle("vehicle1", "north");
    Vehicle* vehicle2 = create_test_vehicle("vehicle2", "west");

    queue_push(queue, vehicle1, "north");
    queue_push(queue, vehicle2, "east");

    Vehicle* poppedVehicle = queue_pop(queue);
    ck_assert_str_eq(poppedVehicle->id, "vehicle1");
    free(poppedVehicle);

    ck_assert_int_eq(queue->size, 1);
    ck_assert_str_eq(queue->front->data->id, "vehicle2");

    queue_destroy(queue);
}
END_TEST

START_TEST(test_queue_is_empty)
{
    Queue* queue = queue_create();
    ck_assert(queue_isEmpty(queue));

    Vehicle* vehicle1 = create_test_vehicle("vehicle1", "north");
    queue_push(queue, vehicle1, "north");
    ck_assert(!queue_isEmpty(queue));

    queue_pop(queue);
    ck_assert(queue_isEmpty(queue));

    queue_destroy(queue);
}
END_TEST

START_TEST(test_queue_destroy)
{
    Queue* queue = queue_create();
    Vehicle* vehicle1 = create_test_vehicle("vehicle1", "north");
    queue_push(queue, vehicle1, "north");

    ck_assert_int_eq(queue->size, 1);
    
    queue_destroy(queue);
}
END_TEST

Suite* queue_suite(void)
{
    Suite* s = suite_create("Queue");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_queue_creation);
    tcase_add_test(tc_core, test_queue_push);
    tcase_add_test(tc_core, test_queue_pop);
    tcase_add_test(tc_core, test_queue_is_empty);
    tcase_add_test(tc_core, test_queue_destroy);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite* s = queue_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}