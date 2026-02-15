#include "sensor_data.h"

#include <string.h>

static uint16_t be16_to_u16(const uint8_t hi, const uint8_t lo)
{
    return (uint16_t)(((uint16_t)hi << 8) | (uint16_t)lo);
}

void sensor_raw_to_eng(const uint8_t raw[SENSOR_RAW_FRAME_SIZE], sensor_eng_data_t *out)
{
    uint16_t temp_raw;
    uint16_t volt_raw;
    uint16_t curr_raw;

    if ((raw == NULL) || (out == NULL)) {
        return;
    }

    temp_raw = be16_to_u16(raw[0], raw[1]);
    volt_raw = be16_to_u16(raw[2], raw[3]);
    curr_raw = be16_to_u16(raw[4], raw[5]);

    out->temperature_c = ((float)temp_raw) / 100.0f;
    out->voltage_v = ((float)volt_raw) / 1000.0f;
    out->current_a = ((float)curr_raw) / 1000.0f;
}

size_t sensor_eng_to_payload(const sensor_eng_data_t *in, uint8_t *payload, size_t payload_size)
{
    if ((in == NULL) || (payload == NULL) || (payload_size < sizeof(sensor_eng_data_t))) {
        return 0u;
    }

    memcpy(payload, in, sizeof(sensor_eng_data_t));
    return sizeof(sensor_eng_data_t);
}
