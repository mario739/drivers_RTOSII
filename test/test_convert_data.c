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

    uint8_t buffer_int3[]={'(','0','0','F','F','C','H','o','l','a','_','m','u','n','d','o','F','F',')'};
    package.count_buffer=19;
    package.buffer=buffer_int3;
    convert_snake_case(&package);
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,19);
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

void test_process_package_to_snake(void)
{
    ///TEST CAMEL-SNAKE
    //tstmsg = '(0000ShelloWorld43)'
    //expmsg = '(0000Shello_world2E)'
    ts_frame package;
    uint8_t buffer_int[]={'(','0','0','0','0','S','h','e','l','l','o','W','o','r','l','d','B','4',')'};
    uint8_t buffer_out[]={'(','0','0','0','0','S','h','e','l','l','o','_','w','o','r','l','d','B','4',')'};
    package.count_buffer=19;
    package.buffer=buffer_int;
    process_package(&package);
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,20);
    //TEST PASCAL-SNAKE
    //tstmsg = '(0000SHelloWorld60)'
    //expmsg = '(0000Shello_world2E)'
    uint8_t buffer_int2[]={'(','0','0','0','0','S','H','e','l','l','o','W','o','r','l','d','B','4',')'};
    uint8_t buffer_out2[]={'(','0','0','0','0','S','h','e','l','l','o','_','w','o','r','l','d','B','4',')'};
    package.count_buffer=19;
    package.buffer=buffer_int2;
    process_package(&package);
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out2,package.buffer,20);
}

void test_procees_to_pascal(void)
{
    //TEST PASCAL-CAMEL
    //tstmsg = '(0000CHelloWorld97)'
    //expmsg = '(0000ChelloWorldB4)'
    ts_frame package;
    uint8_t buffer_int[]={'(','0','0','0','0','C','H','e','l','l','o','W','o','r','l','d','9','7',')'};
    uint8_t buffer_out[]={'(','0','0','0','0','C','h','e','l','l','o','W','o','r','l','d','9','7',')'};
    package.count_buffer=19;
    package.buffer=buffer_int;
    process_package(&package);
    printf(package.buffer);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_out,package.buffer,19);
    //TEST PASCAL-CAMEL
    //tstmsg = '(0000CHelloWorld97)'
    //expmsg = '(0000ChelloWorldB4)'

}