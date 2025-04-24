#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/roadway.h"
#include "../include/traffic_lights.h"
#include "../include/queue.h"

START_TEST(test_roadway_create)
{
    Roadway* roadway = roadway_create();
    ck_assert_ptr_nonnull(roadway);
    ck_assert_ptr_nonnull(roadway->straightLane);
    ck_assert_ptr_nonnull(roadway->straightLights);

    ck_assert_int_eq(roadway->straightLane->size, 0);

    roadway_destroy(roadway);
}
END_TEST

START_TEST(test_roadway_initialize)
{
    Roadway* roadway = roadway_create();
    roadway_initialize(roadway);

    ck_assert_ptr_nonnull(roadway->straightLane);
    ck_assert_int_eq(roadway->straightLane->size, 0);
    ck_assert_ptr_nonnull(roadway->straightLights);
    ck_assert_int_eq(roadway->straightLights->greenLight->isActive, 0);
    ck_assert_int_eq(roadway->straightLights->yellowLight->isActive, 0);
    ck_assert_int_eq(roadway->straightLights->redLight->isActive, 0);

    roadway_destroy(roadway);
}
END_TEST

START_TEST(test_roadway_destroy)
{
    Roadway* roadway = roadway_create();
    ck_assert_ptr_nonnull(roadway);

    roadway_destroy(roadway);
}
END_TEST

Suite* roadway_suite(void)
{
    Suite* s = suite_create("Roadway");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_roadway_create);
    tcase_add_test(tc_core, test_roadway_initialize);
    tcase_add_test(tc_core, test_roadway_destroy);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite* s = roadway_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}