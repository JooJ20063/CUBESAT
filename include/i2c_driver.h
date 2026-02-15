#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include <rtems.h>
#include <stddef.h>
#include <stdint.h>

/* Exemplo de endereço I2C para a suíte de sensores */
#define SENSOR_I2C_ADDR 0x40u

/* Inicializa interface I2C (clock, pinos e controlador). */
rtems_status_code i2c_init(void);

/*
 * Lê bytes brutos do sensor via I2C.
 * raw_data: buffer de destino.
 * len: quantidade de bytes esperada.
 */
rtems_status_code i2c_read_sensor(uint8_t *raw_data, size_t len);

#endif
