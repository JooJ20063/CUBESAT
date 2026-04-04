/* rtems_msg.h */

#ifndef RTEMS_MSG_H
#define RTEMS_MSG_H

#include <stdint.h>

/* Definition of all possible types of messages. */
typedef enum {
    MSG_SENSOR_DATA,
    MSG_CMD_EXEC,
    MSG_HEALTH_REPORT,
    MSG_ERROR,
    MSG_TELEMETRY,
} msg_type_t;

/* Message format definition. */
typedef struct {
    msg_type_t type;
    uint32_t source;
    uint32_t destination;
    uint32_t timestamp;
    uint8_t payload[32];
} __attribute__((packed)) rtems_msg_t;

#endif
