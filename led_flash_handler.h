#include <stdio.h>
#include <stdbool.h>
#include <dio_sudo.h>       // to be replaced by dio.h

/*
led_1_handler function is used to turn on/off user led 1.
input parameter: bool turn_on   : true to turn ON led 1
                                : false to turn OFF led 1
return type: None
*/
void led_1_handler (bool turn_on)
{
    if (turn_on){
        Dio_WriteChannel(1, STD_HIGH);
    }else{
        Dio_WriteChannel(1, STD_LOW);
    }
}


/*
led_2_handler function is used to turn on/off user led 2.
input parameter: bool turn_on   : true to turn ON led 2
                                : false to turn OFF led 2
return type: None
*/
void led_2_handler (bool turn_on)
{
    if (turn_on){
        Dio_WriteChannel(2, STD_HIGH);
    }else{
        Dio_WriteChannel(2, STD_LOW);
    }
}


/*
led_4_5_6_handler function is used to turn on/off user led 4, 5 & 6.


input parameter: Dio_ChannelGroupType  led_number
                                    {
                                    uint8_t     mask    This element mask which defines the positions of the channel group.
                                    uint8_t     offset  This element shall be the position of the Channel Group on the port,
                                                        counted from the LSB.
                                    uint8_t     port    This shall be the port on which the Channel group is defined.
                                    }
                                    Value         led 4       led 5       led 6
                 uint8_t binary_code:   1           OFF         OFF         ON          //ZeC
                                        2           OFF         ON          OFF         //VCP
                                        3           OFF         ON          ON          //ADAS
                                        4           ON          OFF         OFF         //ICP
                                        5           ON          OFF         ON          //ConMod
                                        6           ON          ON          OFF         //SCP
return type: None
*/
void led_4_5_6_handler(uint8_t binary_code)
{
    Dio_ChannelGroupType led_number;
    led_number.port =0;         //this value needs to be changed with respect to hardware
    led_number.offset=0;        //this value needs to be changed with respect to hardware
    led_number.mask=3;
    Dio_WriteChannelGroup(led_number, binary_code);
}



