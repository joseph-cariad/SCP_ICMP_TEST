#ifndef TCPIP_ICMPMSGHANDLER_H_INCLUDED
#define TCPIP_ICMPMSGHANDLER_H_INCLUDED

#include <TcpIp.h>
#include <SoAd.h>


void TcpIp_IcmpMsgHandler(
TcpIp_LocalAddrIdType LocalAddrId,
const TcpIp_SockAddrType* RemoteAddrPtr,
uint8 Ttl,
uint8 Type,
uint8 Code,
uint16 DataLength,
uint8* DataPtr
);

#endif // TCPIP_ICMPMSGHANDLER_H_INCLUDED
