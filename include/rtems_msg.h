/* rtems_msg.h */

#ifndef RTEMS_MSG_H
#define RTEMS_MSG_H
#include <stdint.h>

// Definition of all possible types of messages. Change as needed for your project.

typedef enum {
    MSG_SENSOR_DATA,
    MSG_CMD_EXEC,
    MSG_HEALTH_REPORT
    MSG_ERROR,
    MSG_TELEMETRY,
} msg_type_t;

// Message format definition.
typedef struct {
    msg_type_t type;
    uint32_t source;
    uint32_t destination;
    uint32_t timestamp;
    uint8_t payload[32]; // At first I thought that the uint32_t would be better, but some people told me that uint8_t is better for generic bytes. You can change it, just as far as you remember that future problems could apear.
} __attribute__((packed)) rtems_msg_t;

#endif
