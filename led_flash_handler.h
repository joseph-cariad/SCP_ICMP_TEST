#ifndef _LED_FLASH_HANDLER_H_
#define _LED_FLASH_HANDLER_H_


#include <stdio.h>
#include <stdbool.h>
#include <dio.h>       // to be replaced by dio.h

/*
led_1_handler function is used to turn on/off user led 1(149).
input parameter: bool turn_on   : true to turn ON led 1
                                : false to turn OFF led 1
return type: None
*/
void led_1_handler (bool turn_on)
{
    if (turn_on){
        Dio_WriteChannel(149, STD_HIGH);
    }else{
        Dio_WriteChannel(149, STD_LOW);
    }
}


/*
led_2_handler function is used to turn on/off user led 2 (150).
input parameter: bool turn_on   : true to turn ON led 2
                                : false to turn OFF led 2
return type: None
*/
void led_2_handler (bool turn_on)
{
    if (turn_on){
        Dio_WriteChannel(150, STD_HIGH);
    }else{
        Dio_WriteChannel(150, STD_LOW);
    }
}


/*
led_4_5_6_handler function is used to turn on/off user led 4, 5 & 6.


                                        Value       led 4(152)  led 5(312)  led 6(313)
 input parameter: uint8_t binary_code:  1           OFF         OFF         ON          //ZeC
                                        2           OFF         ON          OFF         //VCP
                                        3           OFF         ON          ON          //ADAS
                                        4           ON          OFF         OFF         //ICP
                                        5           ON          OFF         ON          //ConMod
                                        6           ON          ON          OFF         //SCP
return type: None

*/
void led_4_5_6_handler(uint8_t binary_code)
{
    if (binary_code%2){
        Dio_WriteChannel(313, STD_HIGH); //Led 6(ON)
    }else{
        Dio_WriteChannel(313, STD_LOW);//Led 6(OFF)
    }

    binary_code=binary_code/2;
    if (binary_code%2){
        Dio_WriteChannel(312, STD_HIGH);//Led 5(ON)
    }else{
        Dio_WriteChannel(312, STD_LOW);//Led 5(OFF)
    }

    binary_code=binary_code/2;
    if (binary_code%2){
        Dio_WriteChannel(152, STD_HIGH);//Led 4(ON)
    }else{
        Dio_WriteChannel(152, STD_LOW);//Led 4(OFF)
    }
}

#endif // _LED_FLASH_HANDLER_H_


