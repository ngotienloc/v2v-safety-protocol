#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H
#include <stdint.h>
#pragma pack(push, 1)
typedef struct {
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} Time;

typedef struct {
    uint8_t v; 
    uint8_t gps; 
    Time time; 
} Sensor_Data; 
#pragma pack(pop)
#endif 