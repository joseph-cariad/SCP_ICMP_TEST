#include <stdio.h>
#include <stdint.h>

#include "button_handler.h"

void ButtonHandler()
{
    printf("Hello VW\n");
    uint8_t button1_status;                                     //Variable for Button 1 status
    uint8_t button2_status;                                     //Variable for Button 2 status
    uint8_t noOfTimesButtonPressed;
    uint8_t select;
    button1_status = Dio_readchannel(11);                   // PJ11 as Button 1
    button2_status = Dio_readchannel(12);                   // PJ12 as Button 2
    if((!button1_status)==1)                                //Button 1 is pressed (ping target selection)
    {
        printf("Button 1 is on\n");
        noOfTimesButtonPressed++;
        if((select=noOfTimesButtonPressed%6) == 0)
        {
            select=select+6;
        }
        printf("%d\n",noOfTimesButtonPressed);
        switch(select)
        {
            case 1: printf("Selected target ZeC\n");
                     break;
            case 2: printf("Selected target VCP\n");
                     break;
            case 3: printf("Selected target ADAS\n");
                     break;
            case 4: printf("Selected target ICP\n");
                     break;
            case 5: printf("Selected target ConMod\n");
                     break;
            case 6: printf("Selected target SCP\n");
                     break;
            default: printf("SCP\n");

        }

        if((!button2_status)==1)
        {
            printf("Button 2 is on\n");
            printf("Send notification to ping handler to ping the selected target\n");
            printf("send notification to LED Flash handler to turn on the LED\n");
        }
        else
        {
            printf("Button 2 is not pressed\n");
        }
        

    }
    else
    {
        printf("Button is off\n");
    }

}

uint8_t Dio_readchannel(uint8_t channel)                //Reading the status of button (DIO driver)
{
    
        return STD_LOW;
    
}

