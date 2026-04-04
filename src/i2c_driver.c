#include "i2c_driver.h"

/*
 * Esta implementação é uma base para RTEMS/OBC:
 * - i2c_init: ponto para mux de pinos GPIO -> função alternativa I2C
 * - i2c_read_sensor: ponto para transação I2C real
 *
 * Para manter compilável/integrador-friendly sem BSP específico neste repositório,
 * retornamos dados simulados quando o backend de hardware não estiver ligado.
 */

static int g_i2c_ready = 0;

rtems_status_code i2c_init(void)
{
    /*
     * TODO BSP:
     * 1) Configurar GPIO SDA/SCL para função alternativa I2C.
     * 2) Configurar clock/peripheral reset do controlador I2C.
     * 3) Configurar frequência do barramento (100k/400k).
     */
    g_i2c_ready = 1;
    return RTEMS_SUCCESSFUL;
}

rtems_status_code i2c_read_sensor(uint8_t *raw_data, size_t len)
{
    if ((raw_data == NULL) || (len < 6u)) {
        return RTEMS_INVALID_ADDRESS;
    }

    if (!g_i2c_ready) {
        return RTEMS_INCORRECT_STATE;
    }

    /*
     * Frame de exemplo:
     * temp_raw = 2534 (25.34 ºC)
     * volt_raw = 5012 (5.012 V)
     * curr_raw =  845 (0.845 A)
     */
    raw_data[0] = 0x09;
    raw_data[1] = 0xE6;
    raw_data[2] = 0x13;
    raw_data[3] = 0x94;
    raw_data[4] = 0x03;
    raw_data[5] = 0x4D;

    return RTEMS_SUCCESSFUL;
}
