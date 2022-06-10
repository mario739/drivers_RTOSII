#include "c2_frame.h"

void frame_init(ts_frame *self, uint8_t *buffer, uint8_t max_size_buffer, uint8_t size_buffer, en_frame state_frame, uint8_t count_buffer)
{
    self->buffer = buffer;
    self->max_size_buffer = max_size_buffer;
    self->size_buffer = size_buffer;
    self->state_frame = state_frame;
    self->count_buffer = count_buffer;
}
bool frame_process(ts_frame *self, uint8_t byte)
{
    switch (self->state_frame)
    {
    case SOM:
        if (byte == '(')
        {
            self->buffer[self->count_buffer] = byte;
            self->count_buffer++;
            self->state_frame = EOM;
        }
        break;
    case EOM:
        if (byte == ')')
        {
            self->buffer[self->count_buffer] = byte;
            ts_c2_parser c2_parser;
            self->state_frame = SOM;
            c2_parser_init(&c2_parser, self->buffer, self->count_buffer);
            if (validate_id_hex(&c2_parser) == 1)
            {
                if (validate_crc_hex(&c2_parser) == 1)
                {
                    return 1;
                }
            }
        }
        else
        {
            if (byte == '(')
            {
                self->count_buffer = 0;
                self->buffer[self->count_buffer] = byte;
            }
            else
            {
                self->buffer[self->count_buffer] = byte;
                self->count_buffer++;
            }
        }
        break;
    default:
        break;
    }
}

uint8_t validate_crc(ts_frame *self)
{
    //crc8_calc(0,self->buffer,5);
    return 1;
}
