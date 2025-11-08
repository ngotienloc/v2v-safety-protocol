#include "message.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "message.h"
#include <string.h>  
// Tạo broadcast base message
void init_broadcast_base(message_t *msg, uint16_t messageID, uint32_t vehicleID, uint16_t speed, uint16_t heading, uint16_t elevation, gps_t gpsnow, uint32_t timestamp) {
    memset(msg, 0, sizeof(message_t));
    msg->messageID = messageID;
    msg->vehicleID = vehicleID;
    msg->timestamp = timestamp;
    msg->payload.broadcast_base.speed = speed;
    msg->payload.broadcast_base.heading = heading;
    msg->payload.broadcast_base.elevation = elevation;
    msg->payload.broadcast_base.gpsnow = gpsnow;
}

// Tạo broadcast emergency message
void init_broadcast_emergency(message_t *msg, uint16_t messageID, uint32_t vehicleID, uint16_t type_emergency, gps_t gpsnow, uint16_t speed, uint32_t timestamp) {
    memset(msg, 0, sizeof(message_t));
    msg->messageID = messageID; 
    msg->vehicleID = vehicleID;
    msg->timestamp = timestamp;
    msg->payload.broadcast_emergency.type_emergency = type_emergency;
    msg->payload.broadcast_emergency.gpsnow = gpsnow;
    msg->payload.broadcast_emergency.speed = speed;
}
