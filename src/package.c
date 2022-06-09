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

void convert_snake_case(ts_frame *self)
{
    for (uint8_t i = 6; i < self->count_buffer-4; i++)
    {
        if (self->buffer[i] >= 'A' && self->buffer[i] <= 'Z')
        {
            self->buffer[i]=self->buffer[i]+32;
        }
        else if (self->buffer[i]==' ')
        {
            self->buffer[i]='_';
        }
    }
}

void convert_camel_case(ts_frame *self)
{
    for (uint8_t i = 6; i < self->count_buffer-4; i++)
    {
        if (self->buffer[i]=='_')
        {
            if (self->buffer[i+1] >= 'a' && self->buffer[i+1] <= 'z')
            {
                self->buffer[i+1]=self->buffer[i+1]-32;
            }           
            memmove((void*)self->buffer+i,(void*)self->buffer+i+1,self->count_buffer-i);      
        }
        else if(self->buffer[i] >= 'A' && self->buffer[i] <= 'Z')
        {
            self->buffer[i]=self->buffer[i]+32;
        }    
    }  
}
void convert_pascal_case(ts_frame *self)
{
    for (uint8_t i = 6; i < self->count_buffer-4 ; i++)
    {
        if (i==6)
        {
            if (self->buffer[i] >= 'a' && self->buffer[i] <= 'z')
            {
                self->buffer[i]=self->buffer[i]-32;
            }
        }
        else if (self->buffer[i]=='_')
        {
            if (self->buffer[i+1] >= 'a' && self->buffer[i+1] <= 'z')
            {
                self->buffer[i+1]=self->buffer[i+1]-32;
            }           
            memmove((void*)self->buffer+i,(void*)self->buffer+i+1,self->count_buffer-i);
        }
        else if (self->buffer[i] >= 'A' && self->buffer[i] <= 'Z')
        {
            self->buffer[i]=self->buffer[i]+32;
        }        
    }
}
