void debug_print(char * text_error);

void TcpIp_IcmpMsgHandler( TcpIp_LocalAddrIdType LocalAddrId, const TcpIp_SockAddrType* RemoteAddrPtr, uint8 Ttl, uint8 Type, uint8 Code, uint16 DataLength, uint8* DataPtr );