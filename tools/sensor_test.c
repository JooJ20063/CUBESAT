#include <stdio.h>

#include "sensor_data.h"

int main(void)
{
    const uint8_t raw[SENSOR_RAW_FRAME_SIZE] = {0x09, 0xE6, 0x13, 0x94, 0x03, 0x4D};
    sensor_eng_data_t eng;

    sensor_raw_to_eng(raw, &eng);

    printf("temperature_c=%.2f\n", eng.temperature_c);
    printf("voltage_v=%.3f\n", eng.voltage_v);
    printf("current_a=%.3f\n", eng.current_a);

    return 0;
}
