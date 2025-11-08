#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdint.h>
#include <stdbool.h>
typedef struct
{
    int32_t latitude;
    int32_t longitude; 
} gps_t;

typedef enum { 
    MSG_BROADCAST_BASE = 0,
    MSG_EMERGENCY_CHANGELANE,
    MSG_EMERGENCY_BRAKE,
    MSG_EMERGENCY_OVERSPEED
} message_type;



typedef struct {
    uint16_t messageID; 
    uint32_t vehicleID;
    uint32_t timestamp;
    union{
        struct {
            uint16_t speed; 
            uint16_t heading;
            uint16_t elevation;
            gps_t gpsnow;
        } broadcast_base; 
        struct{
            uint16_t type_emergency; 
            gps_t gpsnow;
            uint16_t speed; 
        } broadcast_emergency; 
    } payload; 
    uint8_t checksum; 
} message_t;

void init_broadcast_base(message_t *msg,uint16_t messageID, uint32_t vehicleID, uint16_t speed, uint16_t heading, uint16_t elevation, gps_t gpsnow, uint32_t timestamp);
void init_broadcast_emergency(message_t *msg, uint16_t messageID,uint32_t vehicleID, uint16_t type_emergency, gps_t gpsnow, uint16_t speed, uint32_t timestamp);


#endif