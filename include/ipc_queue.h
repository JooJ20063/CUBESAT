#ifndef IPC_QUEUE_H
#define IPC_QUEUE_H

#include <rtems.h>
#include "rtems_msg.h" 

// Rather than, writing all of the definitions for the queue, I've opted for a more decentralized approach. You can put the definitions here as well, but remember that they must be the same as those in the rtems_msg.h header to avoid future conflicts.

/*Function Prototypes from those present at the ipc_queue.c file. remember to add future prototypes as needed. */
rtems_status_code ipc_queue_init(void);
rtems_status_code ipc_send(rtems_msg_t *msg);
rtems_status_code ipc_recieve(rtems_msg_t *msg);

#endif
