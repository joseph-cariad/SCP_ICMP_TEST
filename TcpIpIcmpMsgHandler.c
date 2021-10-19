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

TcpIp_IcmpMsgHandler(0,                                   //Local address identifier representing the local IP address        
                     RemoteAddrPtr ,                      //pointer to struct representing the address of the ICMP sender
                     10 ,                                 //Hop Limit value of the received ICMPv6 message.
                     0x80 ,                               //type field value of the reveived ICMP message
                     0x00 ,                               //code field value of the received ICMP message.
                     0 ,                                  //length of ICMP message
                     NULL_PTR                             //Pointer to the received ICMP message
                     );    
    printf("Response is received\n");
    LED2();
}
