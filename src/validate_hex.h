#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
    uint8_t *buffer;
    uint8_t size_buffer;
} ts_validate;

void validate_hex_init(ts_validate *self, uint8_t *buffer, uint8_t size);
bool validate_hex_process(ts_validate *self,uint8_t size);