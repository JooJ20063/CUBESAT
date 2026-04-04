#include "ipc_queue.h"

rtems_task control_task(rtems_task_argument arg)
{
    rtems_msg_t msg;

    (void)arg;

    while (1) {
        if (ipc_receive(&msg) == RTEMS_SUCCESSFUL) {
            if (msg.type == MSG_SENSOR_DATA) {
                /* Control/FDIR logic */
            }
        }
    }
}
