#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "c2_parser.h"
#include "crc8.h"

#ifndef C2_FRAME
#define C2_FRAME
typedef enum
{
    SOM,
    EOM,
} en_frame;
typedef struct
{
    uint8_t *buffer;
    uint8_t max_size_buffer;
    uint8_t size_buffer;
    en_frame state_frame;
    uint8_t count_buffer;
} ts_frame;

void frame_init(ts_frame *self,uint8_t *buffer,uint8_t max_size_buffer,uint8_t size_buffer,en_frame state_frame,uint8_t count_buffer);
bool frame_process(ts_frame *self, uint8_t byte);
uint8_t validate_crc(ts_frame *self);
#endif