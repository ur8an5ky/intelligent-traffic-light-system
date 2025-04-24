#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/traffic_lights.h"

START_TEST(test_trafficLights_create)
{
    TrafficLights* lights = trafficLights_create();
    ck_assert_ptr_nonnull(lights);
    ck_assert_ptr_nonnull(lights->greenLight);
    ck_assert_ptr_nonnull(lights->yellowLight);
    ck_assert_ptr_nonnull(lights->redLight);

    ck_assert_int_eq(lights->greenLight->color, GREEN);
    ck_assert_int_eq(lights->yellowLight->color, YELLOW);
    ck_assert_int_eq(lights->redLight->color, RED);
    
    trafficLights_destroy(lights);
}
END_TEST

START_TEST(test_trafficLights_initialize)
{
    TrafficLights* lights = trafficLights_create();
    trafficLights_initialize(lights);

    ck_assert_int_eq(lights->greenLight->isActive, 0);
    ck_assert_int_eq(lights->yellowLight->isActive, 0);
    ck_assert_int_eq(lights->redLight->isActive, 0);

    trafficLights_destroy(lights);
}
END_TEST

START_TEST(test_trafficLights_update)
{
    TrafficLights* lights = trafficLights_create();
    trafficLights_initialize(lights);

    trafficLights_update(lights->greenLight);
    ck_assert_int_eq(lights->greenLight->isActive, 1);

    trafficLights_update(lights->greenLight);
    ck_assert_int_eq(lights->greenLight->isActive, 0);

    trafficLights_destroy(lights);
}
END_TEST

Suite* traffic_lights_suite(void)
{
    Suite* s = suite_create("Traffic Lights");
    TCase* tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_trafficLights_create);
    tcase_add_test(tc_core, test_trafficLights_initialize);
    tcase_add_test(tc_core, test_trafficLights_update);

    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int number_failed;
    Suite* s = traffic_lights_suite();
    SRunner* sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}