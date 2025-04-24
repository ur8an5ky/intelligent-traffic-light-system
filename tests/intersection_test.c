#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/intersection.h"
#include "../include/traffic_lights.h"
#include "../include/queue.h"
#include "../include/roadway.h"

START_TEST(test_intersection_create)
{
    Intersection* intersection = intersection_create();
    ck_assert_ptr_nonnull(intersection);
    ck_assert_ptr_nonnull(intersection->northRoadway);
    ck_assert_ptr_nonnull(intersection->eastRoadway);
    ck_assert_ptr_nonnull(intersection->southRoadway);
    ck_assert_ptr_nonnull(intersection->westRoadway);

    ck_assert_int_eq(intersection->northRoadway->straightLane->size, 0);
    ck_assert_int_eq(intersection->eastRoadway->straightLane->size, 0);
    ck_assert_int_eq(intersection->southRoadway->straightLane->size, 0);
    ck_assert_int_eq(intersection->westRoadway->straightLane->size, 0);

    intersection_destroy(intersection);
}
END_TEST

START_TEST(test_intersection_initialize)
{
    Intersection* intersection = intersection_create();
    ck_assert_ptr_nonnull(intersection);
    
    intersection_initialize(intersection);

    ck_assert_ptr_nonnull(intersection->northRoadway);
    ck_assert_ptr_nonnull(intersection->eastRoadway);
    ck_assert_ptr_nonnull(intersection->southRoadway);
    ck_assert_ptr_nonnull(intersection->westRoadway);

    intersection_destroy(intersection);
}
END_TEST

START_TEST(test_intersection_destroy)
{
    Intersection* intersection = intersection_create();
    ck_assert_ptr_nonnull(intersection);
    intersection_destroy(intersection);
}
END_TEST

START_TEST(test_intersection_addVehicle)
{
    Intersection* intersection = intersection_create();
    intersection_initialize(intersection);

    Vehicle* testVehicle = vehicle_create("vehicle1", "south");
    ck_assert_ptr_nonnull(testVehicle);

    intersection_addVehicle(intersection, testVehicle, "north", "south");

    ck_assert_int_eq(intersection->northRoadway->straightLane->size, 1);

    intersection_destroy(intersection);
}
END_TEST

Suite* intersection_suite(void)
{
    Suite* s = suite_create("Intersection");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_intersection_create);
    tcase_add_test(tc_core, test_intersection_initialize);
    tcase_add_test(tc_core, test_intersection_destroy);
    tcase_add_test(tc_core, test_intersection_addVehicle);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite* s = intersection_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}