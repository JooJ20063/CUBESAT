#include "ipc_queue.h"

#define QUEUE_NAME rtems_build_name('I', 'P', 'C', '0')
#define MAX_MESSAGES 16

static rtems_id msg_queue_id;

rtems_status_code ipc_queue_init(void)
{
    return rtems_message_queue_create(
        QUEUE_NAME,
        MAX_MESSAGES,
        sizeof(rtems_msg_t),
        RTEMS_FIFO,
        &msg_queue_id
    );
}

rtems_status_code ipc_send(rtems_msg_t *msg)
{
    return rtems_message_queue_send(
        msg_queue_id,
        msg,
        sizeof(rtems_msg_t)
    );
}

rtems_status_code ipc_receive(rtems_msg_t *msg)
{
    size_t size;

    return rtems_message_queue_receive(
        msg_queue_id,
        msg,
        &size,
        RTEMS_WAIT,
        RTEMS_NO_TIMEOUT
    );
}

rtems_status_code ipc_recieve(rtems_msg_t *msg)
{
    return ipc_receive(msg);
}
