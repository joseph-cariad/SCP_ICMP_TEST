#include <stdio.h>
#include <stdbool.h>
     
#include <led_flash_handler.h>
/*
led_1_handler function is used to turn on/off user led 0(150).
input parameter: bool turn_on   : true to turn ON led 0
                                : false to turn OFF led 0
return type: None
*/
void led_0_handler (bool turn_on)
{
    if (turn_on){
        Dio_WriteChannel(150, STD_HIGH);
    }else{
        Dio_WriteChannel(150, STD_LOW);
    }
}


/*
led_2_handler function is used to turn on/off user led 1 (152).
input parameter: bool turn_on   : true to turn ON led 1
                                : false to turn OFF led 1
return type: None
*/
void led_1_handler (bool turn_on)
{
    if (turn_on){
        Dio_WriteChannel(152, STD_HIGH);
    }else{
        Dio_WriteChannel(152, STD_LOW);
    }
}


/*
led_4_5_6_handler function is used to turn on/off user led 3, 4 & 5.


                                        Value       led 3(154)  led 4(281)  led 5(282)
 input parameter: uint8_t binary_code:  1           OFF         OFF         ON          //ZeC
                                        2           OFF         ON          OFF         //VCP
                                        3           OFF         ON          ON          //ADAS
                                        4           ON          OFF         OFF         //ICP
                                        5           ON          OFF         ON          //ConMod
                                        6           ON          ON          OFF         //SCP
return type: None

*/
void led_3_4_5_handler(uint8_t binary_code)
{
    if (binary_code%2){
        Dio_WriteChannel(282, STD_HIGH); //Led 5(ON)
    }else{
        Dio_WriteChannel(282, STD_LOW);//Led 5(OFF)
    }

    binary_code=binary_code/2;
    if (binary_code%2){
        Dio_WriteChannel(281, STD_HIGH);//Led 4(ON)
    }else{
        Dio_WriteChannel(281, STD_LOW);//Led 4(OFF)
    }

    binary_code=binary_code/2;
    if (binary_code%2){
        Dio_WriteChannel(154, STD_HIGH);//Led 3(ON)
    }else{
        Dio_WriteChannel(154, STD_LOW);//Led 3(OFF)
    }
}




