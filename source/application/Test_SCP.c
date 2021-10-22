/*Header file containing declaration of structure TcpIp_SockAddrInet6Type*/
#include <TcpIp_CfgTypes.h>
#include <TcpIp_Api.h>
#include <TSMem.h>


#include <stdio.h>
#include <string.h>

#define IPV6ADDRMEMSIZE                16 /*Length in Bytes for IPv6 Address */

/* Here a Table containing all theIPv6 Address of target devices should be stored.*/
/* From the table selection is made based on BTN1 press */
#define REMOTE_ADDRESS "fd53:7cb8:0383:0001:0000:0000:0000:0073"

uint32 remote_address[4] = {3095155709,16810755,0,1929379840};

void debug_print(char * text_error)
{
    fprintf(stderr,text_error);
}


FUNC(boolean, COM_APPL_CODE) Com_IPdu_256R_Cbk_func
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)

{
  
	printf("PDU Received %d len = %d\n",*(PduInfoPtr->SduDataPtr),PduInfoPtr->SduLength); 

  /* Declaration of variable containing IPv6 details */
  TcpIp_SockAddrInet6Type RemoteAddr;

  /* Fill RemoteAddr with Domain,Port,IPv6 address */
  // NOTE: RemoteAddress should be of integer datatype which will be converted from REMOTE_ADDRESS.
  // The API to be used for converting string to integer to be decided
  TS_MemCpy(RemoteAddr.addr, remote_address, IPV6ADDRMEMSIZE);


  RemoteAddr.port = 0; //Port of remote host
  RemoteAddr.domain = TCPIP_AF_INET6;

  /* Type cast TcpIp_SockAddrInet6Type to TcpIp_SockAddrType to pass on to APIs */
  TcpIp_SockAddrType * const RemoteAddrPtr = (TcpIp_SockAddrType*)&RemoteAddr;
#if 1
  /* Function to be called to transmit ICMP message */
  /* Type 0x80(128) for EchoRequest */
  /* Code : 0x00 */
  /* TTL : 10 */
  TcpIp_IcmpTransmit ( 0,RemoteAddrPtr , 0xFF , 0x80 , 0x00 , 16 , remote_address );
#endif


}

FUNC(void, COM_APPL_CODE) Com_CbkRxAck_Rcv(void)
{
	fprintf(stderr,"signal received");
}

void TcpIp_IcmpMsgHandler( TcpIp_LocalAddrIdType LocalAddrId, const TcpIp_SockAddrType* RemoteAddrPtr, uint8 Ttl, uint8 Type, uint8 Code, uint16 DataLength, uint8* DataPtr )
{
  printf("Ping response received\n");
}