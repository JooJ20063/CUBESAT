#include "ipc_queue.h"
#include "i2c_driver.h"

rtems_task Init(rtems_task_argument arg)
{
    rtems_status_code sc;

    (void)arg;

    sc = ipc_queue_init();
    if (sc != RTEMS_SUCCESSFUL) {
        rtems_fatal_error_occurred(sc);
    }

    sc = i2c_init();
    if (sc != RTEMS_SUCCESSFUL) {
        rtems_fatal_error_occurred(sc);
    }

    /* TODO: criar/start task_sensor e task_control */
    rtems_task_delete(RTEMS_SELF);
}
