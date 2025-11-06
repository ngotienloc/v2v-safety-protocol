#include "utils.h"
// Checksum
uint8_t message_checksum(message_t *msg){
    uint16_t sum = 0; 
    for(uint8_t i = 0; i < msg->payload_len; i++){
        sum += msg->payload[i]; 
    }
    return (uint8_t)(sum & 0xFF); 
}