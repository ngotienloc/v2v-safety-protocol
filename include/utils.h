#ifndef UTILS_H
#define UTILS_H
#include "message.h"

uint8_t crc8_compute(const uint8_t data, uint16_t len); 
uint8_t message_checksum(message_t *msg);

#endif