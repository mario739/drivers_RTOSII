/**
 * @file test_convert_data.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "unity.h"
#include "c2_frame.h"
#include "c2_parser.h"
#include "stdio.h"
#include "package.h"


void test_convert_snake_data(void)
{   
    ts_frame package;
    uint8_t buffer_int[]={'(','0','0','F','F','C','h','o','l','a',' ','m','u','n','d','o','F','F',')'};
    uint8_t buffer_out[]={'(','0','0','F','F','C','h','o','l','a','_','m','u','n','d','o','F','F',')'};
    package.count_buffer=19;
    package.buffer=buffer_int;
    convert_snake_case(&package);
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,19);

    /*uint8_t buffer_int2[]={'(','0','0','F','F','C','h','o','l','a','M','u','n','d','o','F','F',')'};
    package.count_buffer=18;
    package.buffer=buffer_int2;
    convert_snake_case(&package);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,18);*/

    uint8_t buffer_int3[]={'(','0','0','F','F','C','H','O','l','a','_','M','u','n','d','o','F','F',')'};
    package.count_buffer=19;
    package.buffer=buffer_int3;
    convert_snake_case(&package);
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,19);
    
    /*package.count_buffer=18;
    uint8_t buffer_int4[]={'(','0','0','F','F','C','H','O','l','a','M','u','n','d','o','F','F',')'};
    package.buffer=buffer_int4;
    convert_snake_case(&package);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,18);*/
}

void test_convert_camel_case(void)
{
    ts_frame package;
    uint8_t buffer_int[]={'(','0','0','F','F','C','h','o','l','a','_','m','u','n','d','o','F','F',')'};
    uint8_t buffer_out[]={'(','0','0','F','F','C','h','o','l','a','M','u','n','d','o','F','F',')'};
    package.count_buffer=19;
    package.buffer=buffer_int;
    convert_camel_case(&package); 
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,18);
}


void test_convert_pascal_case(void)
{
    ts_frame package;
    uint8_t buffer_int[]={'(','0','0','F','F','C','h','o','l','a','_','m','u','n','d','o','F','F',')'};
    uint8_t buffer_out[]={'(','0','0','F','F','C','H','o','l','a','M','u','n','d','o','F','F',')'};
    package.count_buffer=19;
    package.buffer=buffer_int;
    convert_pascal_case(&package);
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,18);
}