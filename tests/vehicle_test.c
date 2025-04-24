#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/vehicle.h"

START_TEST(test_vehicle_creation)
{
    Vehicle* vehicle = vehicle_create("vehicle123", "north");
    ck_assert_ptr_nonnull(vehicle);
    ck_assert_str_eq(vehicle->id, "vehicle123");
    ck_assert_str_eq(vehicle->endRoad, "north");
    vehicle_destroy(vehicle);
}
END_TEST

START_TEST(test_vehicle_destruction)
{
    Vehicle* vehicle = vehicle_create("vehicle456", "south");
    vehicle_destroy(vehicle);
    ck_assert(1);
}
END_TEST

START_TEST(test_destination_road_truncation)
{
    Vehicle* vehicle = vehicle_create("vehicle789", "VeryLongRoadName");
    ck_assert_ptr_nonnull(vehicle);
    ck_assert_str_eq(vehicle->endRoad, "VeryL");
    vehicle_destroy(vehicle);
}
END_TEST

START_TEST(test_vehicle_id_copy)
{
    Vehicle* vehicle = vehicle_create("vehicle0", "east");
    ck_assert_ptr_nonnull(vehicle);
    ck_assert_str_eq(vehicle->id, "vehicle0");
    vehicle_destroy(vehicle);
}
END_TEST

START_TEST(test_null_id_and_destination)
{
    Vehicle* vehicle = vehicle_create("", "");
    ck_assert_ptr_nonnull(vehicle);
    ck_assert_str_eq(vehicle->id, "");
    ck_assert_str_eq(vehicle->endRoad, "");
    vehicle_destroy(vehicle);
}
END_TEST

START_TEST(test_long_id)
{
    Vehicle* vehicle = vehicle_create("vehicle0123456789", "west");
    ck_assert_ptr_nonnull(vehicle);
    ck_assert_str_eq(vehicle->id, "vehicle0123");
    ck_assert_str_eq(vehicle->endRoad, "west");
    vehicle_destroy(vehicle);
}
END_TEST

START_TEST(test_null_vehicle_destroy)
{
    vehicle_destroy(NULL);
    ck_assert(1);
}
END_TEST

Suite* vehicle_suite(void)
{
    Suite* s = suite_create("vehicle");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_vehicle_creation);
    tcase_add_test(tc_core, test_vehicle_destruction);
    tcase_add_test(tc_core, test_destination_road_truncation);
    tcase_add_test(tc_core, test_vehicle_id_copy);
    tcase_add_test(tc_core, test_null_id_and_destination);
    tcase_add_test(tc_core, test_long_id);
    tcase_add_test(tc_core, test_null_vehicle_destroy);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite* s = vehicle_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}