#include "ipc_queue.h"
#include "i2c_driver.h"
#include "sensor_data.h"

#define TICK_MS 500
#define SENSOR_SOURCE_ID 1u

rtems_task sensor_task(rtems_task_argument arg)
{
    rtems_msg_t msg;
    rtems_status_code sc;
    uint8_t raw[SENSOR_RAW_FRAME_SIZE];
    sensor_eng_data_t eng;

    (void)arg;

    while (1) {
        sc = i2c_read_sensor(raw, sizeof(raw));
        if (sc == RTEMS_SUCCESSFUL) {
            sensor_raw_to_eng(raw, &eng);

            msg.type = MSG_SENSOR_DATA;
            msg.source = SENSOR_SOURCE_ID;
            msg.destination = 0u;
            msg.timestamp = rtems_clock_get_uptime_seconds();

            for (size_t i = 0; i < sizeof(msg.payload); ++i) {
                msg.payload[i] = 0u;
            }

            (void)sensor_eng_to_payload(&eng, msg.payload, sizeof(msg.payload));
            (void)ipc_send(&msg);
        }

        rtems_task_wake_after(RTEMS_MILLISECONDS_TO_TICKS(TICK_MS));
    }
}
