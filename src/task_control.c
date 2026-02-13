#include "include/ipc_queue.h"


rtems_task control_task(rtems_task_argument arg) {
    rtems_msg_t msg;

    while(1) {
    // The ipc_recieve function fills the struct 'msg'
        if (ipc_recieve(&msg) == RTEMS_SUCCESSFUL) { 

          if (msg.type == MSG_SENSOR_DATA){
            // Control logic HERE
            // Ex. if (msg.payload[0] > 50) {...}
          }
        }
    }
}
