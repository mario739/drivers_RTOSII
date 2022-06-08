/**
 * @file package.c
 * @author mario aguilar (fernandoaguilar731010@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "package.h"
void package_init(ts_package *package)
{
    package->buffer=(uint8_t*)malloc(1000);
}

ts_erroy_type validate_data(ts_frame *self)
{

    if ((self->buffer[6]=='_') || (self->buffer[6]==' '))
    {
        return ERROR_INVALID_DATA;
    }

    if ((self->buffer[self->count_buffer-3]=='_') || (self->buffer[self->count_buffer-3]==' '))
    {
        return ERROR_INVALID_DATA;
    }
    
    if (self->buffer[6] !='S' && self->buffer[6] !='C' && self->buffer[6]!='P')
    {
        return ERROR_INVALID_OPCODE;
    }

}
