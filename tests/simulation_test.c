#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "../include/simulation.h"
#include "../include/traffic_lights.h"
#include "../include/queue.h"
#include "../include/roadway.h"

START_TEST(test_simulation_create)
{
    Simulation* simulation = simulation_create();
    ck_assert_ptr_nonnull(simulation);
    ck_assert_ptr_nonnull(simulation->intersection);
    ck_assert_ptr_nonnull(simulation->leftVehicles);
    ck_assert_int_eq(simulation->leftVehiclesCount, 0);
    ck_assert_double_eq(simulation->currentTime, 0.0);
    ck_assert_double_eq(simulation->timeStep, 1.0);

    simulation_destroy(simulation);
}
END_TEST

START_TEST(test_simulation_initialize)
{
    Simulation* simulation = simulation_create();
    intersection_initialize(simulation->intersection);

    ck_assert_ptr_nonnull(simulation->intersection->northRoadway);
    ck_assert_ptr_nonnull(simulation->intersection->eastRoadway);
    ck_assert_ptr_nonnull(simulation->intersection->southRoadway);
    ck_assert_ptr_nonnull(simulation->intersection->westRoadway);

    simulation_destroy(simulation);
}
END_TEST

Suite* simulation_suite(void)
{
    Suite* s = suite_create("Simulation");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_simulation_create);
    tcase_add_test(tc_core, test_simulation_initialize);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite* s = simulation_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}