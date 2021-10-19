#include <stdio.h>
#include <stdlib.h>
#include "Tcpip_Api.h"
#define IPV6ADDRMEMSIZE                16                 /*Length in Bytes for IPv6 Address */

int RemoteAddress;
unsigned char REMOTEADDRESS[][6] = {};                    //array to store ipv6 addresses

TcpIp_SockAddrInet6Type RemoteAddr;                       //Variable containing IPv6 details

MemCpy(RemoteAddr.addr, RemoteAddress, IPV6ADDRMEMSIZE);  //Assign RemoteAddr with Domain,Port,IPv6 address
RemoteAddr.port = 0;
RemoteAddr.domain = TCPIP_AF_INET6;

TcpIp_SockAddrType * const RemoteAddrPtr = (TcpIp_SockAddrType*)&RemoteAddr; //Type cast TcpIp_SockAddrInet6Type to TcpIp_SockAddrType

TcpIp_IcmpMsgHandler(0,RemoteAddrPtr , 10 , 0x80 , 0x00 , 0 , NULL_PTR );     //Function to check if response is received.
{
    printf("Response is received\n");
    LED2();
}
