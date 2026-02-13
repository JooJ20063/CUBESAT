#include "include/ipc_queue.h"

#define TICK 500

rtems_task sensor_task(rtems_task_argument arg) {
    rtems_msg_t msg;

    while(1)  {
        msg.type = MSG_SENSOR_DATA;
        msg.source = 1;
        msg.timestamp = rtems_clock_get_uptime_seconds();
        msg.payload[0] = 42;

        ipc_send(&msg);
        
        rtems_task_wake_after(RTEMS_MILLISECONDS_TO_TICKS(TICK));

    }
}
