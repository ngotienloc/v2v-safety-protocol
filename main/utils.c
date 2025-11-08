#include "utils.h"

#define CRC8_INIT 0x00
#define CRC8_POLY 0x31     //0011 0001 => x^8 +x^5 + x^4 + 1

uint8_t crc8_compute(const uint8_t *data, uint16_t len){
    uint8_t crc = CRC8_INIT; 
    for(uint16_t i =0; i < len; i++){
        crc ^= data[i]; 
        for(uint8_t j = 0; j < 8; j++){
            if(crc & 0x80)
                crc = (crc << 1) ^ CRC8_POLY;
            else 
                crc <<= 1; 
        }
    }
    return crc; 
}
uint8_t message_checksum(message_t *msg){
    msg->checksum = 0; 
    uint8_t *raw = (uint8_t *)msg; 
    uint16_t len = sizeof(message_t) - sizeof(msg->checksum); 
    return crc8_compute(raw, len); 
}