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
    BROADCAST_BASE_MESSAGE,        // 0
    BROADCAST_ALERT_MESSAGE,       // 1
    BROADCAST_EMERGENCY_MESSAGE,   // 2
    UNICAST_MESSAGE,               // 3
} message_id;


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
        } broadcast_emergency; 
        struct {
            uint16_t lane_id; 
            uint16_t speed; 
        } unicast_emergency; 
    } payload; 
} message_t;

void init_broadcast_base(message_t *msg, uint32_t vehicleID, uint16_t speed, uint16_t heading, uint16_t elevation, gps_t gpsnow, uint32_t timestamp);
void init_broadcast_emergency(message_t *msg, uint32_t vehicleID, uint16_t type_emergency, gps_t gpsnow, uint32_t timestamp);
void init_unicast_emergency(message_t *msg, uint32_t vehicleID, uint16_t lane_id, uint16_t speed, uint32_t timestamp);


#endif