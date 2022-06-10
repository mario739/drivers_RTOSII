#include "unity.h"
#include "c2_frame.h"
#include "c2_parser.h"
#include "stdio.h"
#include "crc8.h"


void test_frame_process(void)
{
    uint8_t buffer[]={'(','0','0','F','F','H','o','l','a','_','M','u','n','d','o','F','F',')'};
    uint8_t buffer2[17];
    ts_frame frame;
    frame_init(&frame,buffer2,200,30,SOM,0);
    for (size_t i = 0; i <18; i++)
    {
        if (i==17)
        {
           printf((const char*)frame.buffer);
           TEST_ASSERT_EQUAL(true,frame_process(&frame,buffer[i])); 
        }
        else
        {
            frame_process(&frame,buffer[i]);
        }
    }
    printf((const char*)frame.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(buffer,frame.buffer,18,"no son iguales");    
}

void test_validate_crc(void)
{
    ts_frame package;
    uint8_t data=0;
    uint8_t buffer_int[]={'(','0','0','0','0','m','H','O','L','A','9','7',')'};
    package.buffer=buffer_int;
    TEST_ASSERT_EQUAL_UINT8(123,validate_crc(&package));
}