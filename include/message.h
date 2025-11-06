#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdint.h>
#include <stdbool.h>

#define MSG_MAX_PALYLOAD_LEN 64

// Message type
typedef enum {
    MSG_TYPE_BROADCAST = 0x01,  // 3
    MSB_TYPE_UNICAST   = 0x02,  // 2
    MSB_TYPE_ALERT     = 0x03,  // 1
    MSB_TYPE_STATUS    = 0x04   // 4
} msg_type_t; 

// Message structure
typedef struct {
    uint8_t type; 
    uint8_t src_id; 
    uint8_t dest_id; // Broadcast = 0xFF
    uint16_t seq;    // Sequence number
    uint8_t payload_len;
    uint8_t payload[MSG_MAX_PALYLOAD_LEN]; 
    uint16_t checksum; 
    uint8_t priority; 

} message_t;

// API

// Create message
void message_create(message_t *msg, msg_type_t type,
                    uint8_t src_id, uint8_t dest_id,
                    const uint8_t *data, uint8_t len, uint16_t seq);

// Checksum    
bool message_checksum(message_t *msg); 

// Printlog 
void message_print(const message_t *msg); 

#endif