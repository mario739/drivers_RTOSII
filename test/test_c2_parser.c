#include "unity.h"
#include "c2_parser.h"

void test_leds(void)
{
    TEST_FAIL_MESSAGE("ARRANCAMOS");  
}

void test_id_hex(void)
{
    ts_c2_parser buffer_validate;
    uint8_t buffer_init[]="{00F7CHolaMundo0F}";
    c2_parser_init(&buffer_validate,buffer_init,18);
    TEST_ASSERT_EQUAL_UINT8(true,validate_id_hex(&buffer_validate));
}

void test_crc_hex(void)
{
    ts_c2_parser buffer_validate;
    uint8_t buffer_init[]={'(','0','0','F','F','H','o','l','a','_','M','u','n','d','o','F','F',')'};
    c2_parser_init(&buffer_validate,buffer_init,17);
    TEST_ASSERT_EQUAL_UINT8(true,validate_crc_hex(&buffer_validate));
}

