#include "unity.h"
#include "c2_frame.h"
#include "c2_parser.h"

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
    uint8_t buffer_int[]={'(','0','0','0','0','C' ,'H','e','l','l','o','W','o','r','l','d','9','7',')'};
    package.count_buffer=19;
    package.buffer=buffer_int;
    uint8_t data=validate_crc(&package);
    printf( "%u\n",data);
    TEST_ASSERT_EQUAL_UINT8(0x97,data);
}

void test_convert_ascii_to_uint(void)
{
    uint8_t data[2]={'B','4'};
    uint8_t res=convert_ascii_to_uint(data);
    printf( "%u\n",res);
    TEST_ASSERT_EQUAL_UINT8(0xB4,res);
}

void test_convert_int_to_ascii(void)
{
    uint8_t crc=0x97;
    uint8_t data[2]={0};
    uint8_t data_out[2]={'9','7'};
    convert_uint_to_ascii(data,crc);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(data_out,data,2);
}