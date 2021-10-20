#include <stdio.h>
#include <stdlib.h>
#include "Tcpip_Api.h"
#include "TcpIp_IcmpMsgHandler.h"

int main()
{
    int button2_status;
    
    printf("Enter the value of button2 status:\n");
    scanf("%d", &button2_status);
    
    if(button2_status == 1)
        
        TcpIp_IcmpTransmit ( 0,RemoteAddrPtr , 10 , 0x80 , 0x00 , 0 , NULL_PTR );

    return 0;
}
