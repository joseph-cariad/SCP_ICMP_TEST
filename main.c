#include <stdio.h>
#include <stdlib.h>
#include "Tcpip_Api.h"
#define IPV6ADDRMEMSIZE                16                 /*Length in Bytes for IPv6 Address */

int i, RemoteAddress, Button1_status, count;
unsigned char REMOTEADDRESS[][i] = {};

TcpIp_SockAddrInet6Type RemoteAddr;                       //Variable containing IPv6 details

MemCpy(RemoteAddr.addr, RemoteAddress, IPV6ADDRMEMSIZE);  //
RemoteAddr.port = 0;
RemoteAddr.domain = TCPIP_AF_INET6;


TcpIp_SockAddrType * const RemoteAddrPtr = (TcpIp_SockAddrType*)&RemoteAddr;

void Up_IcmpMsgHandler();
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

TcpIp_IcmpMsgHandler(0,RemoteAddrPtr , 10 , 0x80 , 0x00 , 0 , NULL_PTR )
{
    printf("Response is received\n");
    LED2();
}



