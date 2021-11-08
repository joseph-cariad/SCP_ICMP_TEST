#ifndef _LED_FLASH_HANDLER_H_
#define _LED_FLASH_HANDLER_H_

#include <stdio.h>
#include <stdbool.h>
#include <dio.h>   

extern void led_0_handler (bool turn_on); //led_0_handler function is used to turn on/off user led 0(150)

extern void led_1_handler (bool turn_on); //led_1_handler function is used to turn on/off user led 1(152).

extern void led_3_4_5_handler(uint8_t binary_code); //led_3_4_5_handler function is used to turn on/off user led 3, 4 & 5.

#endif // _LED_FLASH_HANDLER_H_