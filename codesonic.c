#include <stdint.h>
#include "codesonic.h"

#include "pico/stdlib.h"

#define TRIG_PIN 14
#define ECHO_PIN 15

#define SPEED_OF_SOUND 343.0f

#define ECHO_RISE_TIMEOUT_US  30000u   
#define ECHO_FALL_TIMEOUT_US  30000u  

void initUltrasonic(void) {
    gpio_init(TRIG_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_put(TRIG_PIN, 0);

    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

static inline uint64_t now_us(void) {
    return time_us_64();
}

float readUltrasonic(void) {
    gpio_put(TRIG_PIN, 0);
    sleep_us(2);

    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    uint64_t t0 = now_us();
    while (gpio_get(ECHO_PIN) == 0) {
        if ((now_us() - t0) > ECHO_RISE_TIMEOUT_US) {
            return -1.0f;
        }
    }
    uint64_t echo_start = now_us();

    while (gpio_get(ECHO_PIN) == 1) {
        if ((now_us() - echo_start) > ECHO_FALL_TIMEOUT_US) {
            return -1.0f; 
        }
    }
    uint64_t echo_end = now_us();

    uint64_t echo_us = echo_end - echo_start;

    float t_sec = (float)echo_us / 1e6f;
    float distance_m = (SPEED_OF_SOUND * t_sec) / 2.0f;

    return distance_m;
}