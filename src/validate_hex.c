
#include "validate_hex.h"

void validate_hex_init(ts_validate *self, uint8_t *buffer, uint8_t size)
{
    self->buffer = buffer;
    self->size_buffer = size;
}

bool validate_hex_process(ts_validate *self,uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        if (!((self->buffer[i] <= 70 && self->buffer[i] >= 65) || (self->buffer[i] <= 57 && self->buffer[i] >= 48)))
        {
            return false;
        }
    }
    return true;
}
bool validate_crc8(ts_validate *self)
{

}