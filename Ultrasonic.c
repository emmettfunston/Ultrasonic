#include <stdio.h>
#include "pico/stdlib.h"

#include "codesonic.h"

static void distance_to_4chars(float m, char out[4]) {
    if (m < 0) { out[0]='-'; out[1]='-'; out[2]='-'; out[3]='-'; return; }

    if (m > 9.999f) m = 9.999f;
    if (m < 0.0f)   m = 0.0f;

    int v = (int)(m * 1000.0f + 0.5f); 
    out[0] = '0' + (v / 1000) % 10;
    out[1] = '0' + (v / 100)  % 10;
    out[2] = '0' + (v / 10)   % 10;
    out[3] = '0' + (v / 1)    % 10;
}

int main(void) {
    stdio_init_all();
    initUltrasonic();

    sleep_ms(2000);

    while (true) {
        float d = readUltrasonic();

        printf("Distance: %.3f m\n", d);

        distance_to_4chars(d, buf);

        sleep_ms(50); 
    }
}