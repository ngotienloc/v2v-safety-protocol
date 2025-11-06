#include "message.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
// Create message
void message_create(message_t *msg, msg_type_t type,
                    uint8_t src_id, uint8_t dest_id,
                    const uint8_t *data, uint8_t len, uint16_t seq)
{
    if(len > MSG_MAX_PALYLOAD_LEN) len = MSG_MAX_PALYLOAD_LEN;

    msg->type = type;
    msg->src_id = src_id;
    msg->dest_id = dest_id;
    msg->seq = seq;
    msg->payload_len = len;

    memcpy(msg->payload, data, len); 
   // msg->checksum = message_checksum(msg);
}

// Checksum

// Printlog
// ===== In ra log =====
void message_print(const message_t *msg)
{
    printf("---- MESSAGE ----\n");
    printf("Type: %02X | Src: %d | Dest: %d | Seq: %d\n",
           msg->type, msg->src_id, msg->dest_id, msg->seq);
    

    printf("Payload: ");
    for (int i = 0; i < msg->payload_len; i++)
        printf("%02X ", msg->payload[i]);
    printf("\n-----------------\n");
}