#include <stdio.h>
#include <stdlib.h>
#include "Tcpip_Api.h"

int main()
{
    int button_status;
    
    printf("Enter the value of button status:\n");
    scanf("%d", &button_status);
    
    if(button_status == 1)
        button_status++;
        TcpIp_IcmpTransmit ( 0,RemoteAddrPtr , 10 , 0x80 , 0x00 , 0 , NULL_PTR );

    return 0;
}