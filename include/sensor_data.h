#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <stddef.h>
#include <stdint.h>

#define SENSOR_RAW_FRAME_SIZE 6u

/* Valores em unidades de engenharia */
typedef struct {
    float temperature_c;
    float voltage_v;
    float current_a;
} sensor_eng_data_t;

/* Converte bytes brutos [T_H T_L V_H V_L I_H I_L] em Eng. Units */
void sensor_raw_to_eng(const uint8_t raw[SENSOR_RAW_FRAME_SIZE], sensor_eng_data_t *out);

/* Serializa os valores de engenharia no payload da mensagem */
size_t sensor_eng_to_payload(const sensor_eng_data_t *in, uint8_t *payload, size_t payload_size);

#endif
