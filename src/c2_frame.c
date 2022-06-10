#include "c2_frame.h"

uint8_t crc8_init(void);
uint8_t crc8_calc(uint8_t val, void *buf, int cnt);

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
    uint8_t data_crc=crc8_calc(0,self->buffer+1,self->count_buffer-4);
    return data_crc;
}
uint8_t convert_ascii_to_uint(uint8_t *data)
{
	uint8_t result = 0;
	if (data[0] >= 'A' && data[0] <= 'F')
		result = (10 + data[0] - 'A') * 16;
	else
		result = (data[0] - '0') * 16;

	if (data[1] >= 'A' && data[1] <= 'F')
		result += 10 + data[1] - 'A';
	else
		result += data[1] - '0';

	return result;
}

static uint8_t crc8_small_table[16] = {
    0x00, 0x07, 0x0e, 0x09, 0x1c, 0x1b, 0x12, 0x15,
    0x38, 0x3f, 0x36, 0x31, 0x24, 0x23, 0x2a, 0x2d
};

uint8_t crc8_calc(uint8_t val, void *buf, int cnt)
{
	int i;
	uint8_t *p = buf;

	for (i = 0; i < cnt; i++) {
		val ^= p[i];
		val = (val << 4) ^ crc8_small_table[val >> 4];
		val = (val << 4) ^ crc8_small_table[val >> 4];
	}
	return val;
}