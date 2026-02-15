#ifndef IPC_QUEUE_H
#define IPC_QUEUE_H

#include <rtems.h>
#include "rtems_msg.h"

rtems_status_code ipc_queue_init(void);
rtems_status_code ipc_send(rtems_msg_t *msg);
rtems_status_code ipc_receive(rtems_msg_t *msg);


#endif
