#include "unity.h"
#include "c2_frame.h"
#include "c2_parser.h"
#include "stdio.h"
#include "package.h"


void test_validate_data(void)
{   
    ts_frame package={.count_buffer=18};
    //prueba para validar si el primer byte de datos no es '_'
    uint8_t buffer2[]={'(','0','0','F','F','C','h','o','l','a','_','M','u','n','d','o','F','F',')'};
    package.buffer=buffer2;

    TEST_ASSERT_EQUAL(NO_ERROR,validate_data(&package));

    //prueba para validar si el byte de comando es correcto 
    uint8_t buffer3[]={'(','0','0','F','F','C','H','o','l','a','_','M','u','n','d','o','F','F',')'};
    package.buffer=buffer3;
    TEST_ASSERT_EQUAL(NO_ERROR,validate_data(&package));

    //prueba para validar si el ultimo byte no es '_'
    uint8_t buffer4[]={'(','0','0','F','F','C','H','o','l','a','_','M','u','n','d','o','F','F',')'};
    package.buffer=buffer4;
    TEST_ASSERT_EQUAL(NO_ERROR,validate_data(&package));
}