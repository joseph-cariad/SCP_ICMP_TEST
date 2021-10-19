// this header file is to be replaced by the dio.h header file provided in autocore os

#include <stdio.h>
#include <stdint.h>

#define STD_LOW         0x00
#define STD_HIGH        0x01

typedef struct{
    uint8_t mask;
    uint8_t offset;
    uint8_t port;
}Dio_ChannelGroupType;

void Dio_WriteChannel(uint8_t led_number, uint8_t level)
{
    printf("LED %d is set to %d \n", led_number, level);
}
void Dio_WriteChannelGroup(Dio_ChannelGroupType led_number , uint8_t level)
{
    printf("LED %d %d %d is set to %d \n", 4,5,6, level);
}

