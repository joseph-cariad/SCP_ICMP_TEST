#include <stdio.h>
#include <OS_task_10ms.h>

uint8_t delay_counter=0;

void OS_task_10ms()
{
    delay_counter++;
    if(delay_counter==50){
        led_0_handler(true);
    }else if(delay_counter==100){
        delay_counter=0;
        led_0_handler(false);
    }
}