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
    //valida si el primer byte de datos no es '_'
    if ((self->buffer[6]=='_') || (self->buffer[6]==' '))
    {
        return ERROR_INVALID_DATA;
    }
    //valida si el byte de comando es correcto
    if (self->buffer[5] !='S' && self->buffer[5] !='C' && self->buffer[5]!='P')
    {
        return ERROR_INVALID_OPCODE;
    }
    //valida si el ultimo byte no es '_'
    if ((self->buffer[self->count_buffer-3]=='_') || (self->buffer[self->count_buffer-3]==' '))
    {
        return ERROR_INVALID_DATA;
    }
    
    return NO_ERROR;
}
