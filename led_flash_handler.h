#ifndef _LED_FLASH_HANDLER_H_
#define _LED_FLASH_HANDLER_H_

#include <stdio.h>
#include <stdbool.h>
#include <dio.h>   

extern void led_1_handler (bool turn_on);

extern void led_2_handler (bool turn_on);

extern void led_4_5_6_handler(uint8_t binary_code);

#endif // _LED_FLASH_HANDLER_H_