/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/
#if SUPPORTS_PRAGMA_PACK
#pragma pack (push,4)
#endif


#ifndef NAMES_ONLY
#define AUTOGENERATE_NAME(name) extern FName IPDRV_##name;
#define AUTOGENERATE_FUNCTION(cls,idx,name)
#endif

AUTOGENERATE_NAME(Accepted)
AUTOGENERATE_NAME(Closed)
AUTOGENERATE_NAME(Opened)
AUTOGENERATE_NAME(ReceivedBinary)
AUTOGENERATE_NAME(ReceivedLine)
AUTOGENERATE_NAME(ReceivedText)
AUTOGENERATE_NAME(Resolved)
AUTOGENERATE_NAME(ResolveFailed)

#ifndef NAMES_ONLY

enum EReceiveMode
{
    RMODE_Manual            =0,
    RMODE_Event             =1,
    RMODE_MAX               =2,
};
enum ELinkMode
{
    MODE_Text               =0,
    MODE_Line               =1,
    MODE_Binary             =2,
    MODE_MAX                =3,
};

struct InternetLink_eventResolveFailed_Parms
{
};
struct InternetLink_eventResolved_Parms
{
    FIpAddr Addr;
};
class AInternetLink : public AInternetInfo
{
public:
    BYTE LinkMode;
    BYTE ReceiveMode;
    INT Socket GCC_PACK(PROPERTY_ALIGNMENT);
    INT Port;
    INT RemoteSocket;
    INT PrivateResolveInfo;
    INT DataPending;
    DECLARE_FUNCTION(execGetLocalIP);
    DECLARE_FUNCTION(execStringToIpAddr);
    DECLARE_FUNCTION(execIpAddrToString);
    DECLARE_FUNCTION(execGetLastError);
    DECLARE_FUNCTION(execResolve);
    DECLARE_FUNCTION(execParseURL);
    DECLARE_FUNCTION(execIsDataPending);
    void eventResolveFailed()
    {
		UObject::ProcessEvent(FindFunctionChecked(IPDRV_ResolveFailed),NULL);
    }
    void eventResolved(FIpAddr Addr)
    {
        InternetLink_eventResolved_Parms Parms;
        Parms.Addr=Addr;
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_Resolved),&Parms);
    }
    DECLARE_CLASS(AInternetLink,AInternetInfo,0|CLASS_Transient,IpDrv)
	AInternetLink();
	void Destroy();
	UBOOL Tick( FLOAT DeltaTime, enum ELevelTick TickType );	
	SOCKET& GetSocket() 
	{ 
		return *(SOCKET*)&Socket;
	}
	FResolveInfo*& GetResolveInfo()
	{
		return *(FResolveInfo**)&PrivateResolveInfo;
	}
};

enum ELinkState
{
    STATE_Initialized       =0,
    STATE_Ready             =1,
    STATE_Listening         =2,
    STATE_Connecting        =3,
    STATE_Connected         =4,
    STATE_ListenClosePending=5,
    STATE_ConnectClosePending=6,
    STATE_ListenClosing     =7,
    STATE_ConnectClosing    =8,
    STATE_MAX               =9,
};

struct TcpLink_eventReceivedBinary_Parms
{
    INT Count;
    BYTE B[255];
};
struct TcpLink_eventReceivedLine_Parms
{
    FString Line;
};
struct TcpLink_eventReceivedText_Parms
{
    FString Text;
};
struct TcpLink_eventClosed_Parms
{
};
struct TcpLink_eventOpened_Parms
{
};
struct TcpLink_eventAccepted_Parms
{
};
class ATcpLink : public AInternetLink
{
public:
    BYTE LinkState;
    TArrayNoInit<BYTE> SendFIFO GCC_PACK(PROPERTY_ALIGNMENT);
    FIpAddr RemoteAddr;
    class UClass* AcceptClass;
    DECLARE_FUNCTION(execReadBinary);
    DECLARE_FUNCTION(execReadText);
    DECLARE_FUNCTION(execSendBinary);
    DECLARE_FUNCTION(execSendText);
    DECLARE_FUNCTION(execIsConnected);
    DECLARE_FUNCTION(execClose);
    DECLARE_FUNCTION(execOpen);
    DECLARE_FUNCTION(execListen);
    DECLARE_FUNCTION(execBindPort);
    void eventReceivedBinary(INT Count, BYTE* B)
    {
        TcpLink_eventReceivedBinary_Parms Parms;
        Parms.Count=Count;
        appMemcpy(&Parms.B,&B,sizeof(Parms.B));
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_ReceivedBinary),&Parms);
    }
    void eventReceivedLine(const FString& Line)
    {
        TcpLink_eventReceivedLine_Parms Parms;
        Parms.Line=Line;
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_ReceivedLine),&Parms);
    }
    void eventReceivedText(const FString& Text)
    {
        TcpLink_eventReceivedText_Parms Parms;
        Parms.Text=Text;
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_ReceivedText),&Parms);
    }
    void eventClosed()
    {
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_Closed),NULL);
    }
    void eventOpened()
    {
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_Opened),NULL);
    }
    void eventAccepted()
    {
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_Accepted),NULL);
    }
    DECLARE_CLASS(ATcpLink,AInternetLink,0|CLASS_Transient,IpDrv)
	ATcpLink();
	void PostScriptDestroyed();
	UBOOL Tick( FLOAT DeltaTime, enum ELevelTick TickType );	

	void CheckConnectionAttempt();
	void CheckConnectionQueue();
	void PollConnections();
	UBOOL FlushSendBuffer();
	void ShutdownConnection();
	virtual UBOOL ShouldTickInEntry() { return true; }
};


struct UdpLink_eventReceivedBinary_Parms
{
    FIpAddr Addr;
    INT Count;
    BYTE B[255];
};
struct UdpLink_eventReceivedLine_Parms
{
    FIpAddr Addr;
    FString Line;
};
struct UdpLink_eventReceivedText_Parms
{
    FIpAddr Addr;
    FString Text;
};
class AUdpLink : public AInternetLink
{
public:
    INT BroadcastAddr;
    DECLARE_FUNCTION(execReadBinary);
    DECLARE_FUNCTION(execReadText);
    DECLARE_FUNCTION(execSendBinary);
    DECLARE_FUNCTION(execSendText);
    DECLARE_FUNCTION(execBindPort);
    void eventReceivedBinary(FIpAddr Addr, INT Count, BYTE* B)
    {
        UdpLink_eventReceivedBinary_Parms Parms;
        Parms.Addr=Addr;
        Parms.Count=Count;
        appMemcpy(&Parms.B,&B,sizeof(Parms.B));
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_ReceivedBinary),&Parms);
    }
    void eventReceivedLine(FIpAddr Addr, const FString& Line)
    {
        UdpLink_eventReceivedLine_Parms Parms;
        Parms.Addr=Addr;
        Parms.Line=Line;
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_ReceivedLine),&Parms);
    }
    void eventReceivedText(FIpAddr Addr, const FString& Text)
    {
        UdpLink_eventReceivedText_Parms Parms;
        Parms.Addr=Addr;
        Parms.Text=Text;
        UObject::ProcessEvent(FindFunctionChecked(IPDRV_ReceivedText),&Parms);
    }
    DECLARE_CLASS(AUdpLink,AInternetLink,0|CLASS_Transient,IpDrv)
	AUdpLink();
	void PostScriptDestroyed();
	UBOOL Tick( FLOAT DeltaTime, enum ELevelTick TickType );	
	FSocketData GetSocketData();
};

#endif

AUTOGENERATE_FUNCTION(AInternetLink,-1,execGetLocalIP);
AUTOGENERATE_FUNCTION(AInternetLink,-1,execStringToIpAddr);
AUTOGENERATE_FUNCTION(AInternetLink,-1,execIpAddrToString);
AUTOGENERATE_FUNCTION(AInternetLink,-1,execGetLastError);
AUTOGENERATE_FUNCTION(AInternetLink,-1,execResolve);
AUTOGENERATE_FUNCTION(AInternetLink,-1,execParseURL);
AUTOGENERATE_FUNCTION(AInternetLink,-1,execIsDataPending);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execReadBinary);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execReadText);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execSendBinary);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execSendText);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execIsConnected);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execClose);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execOpen);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execListen);
AUTOGENERATE_FUNCTION(ATcpLink,-1,execBindPort);
AUTOGENERATE_FUNCTION(AUdpLink,-1,execReadBinary);
AUTOGENERATE_FUNCTION(AUdpLink,-1,execReadText);
AUTOGENERATE_FUNCTION(AUdpLink,-1,execSendBinary);
AUTOGENERATE_FUNCTION(AUdpLink,-1,execSendText);
AUTOGENERATE_FUNCTION(AUdpLink,-1,execBindPort);

#ifndef NAMES_ONLY
#undef AUTOGENERATE_NAME
#undef AUTOGENERATE_FUNCTION
#endif

#if SUPPORTS_PRAGMA_PACK
#pragma pack (pop)
#endif

#ifdef STATIC_LINKING_MOJO
#ifndef IPDRV_NATIVE_DEFS
#define IPDRV_NATIVE_DEFS

DECLARE_NATIVE_TYPE(IpDrv,AInternetLink);
DECLARE_NATIVE_TYPE(IpDrv,ATcpLink);
DECLARE_NATIVE_TYPE(IpDrv,AUdpLink);

#define AUTO_INITIALIZE_REGISTRANTS_IPDRV \
	AInternetLink::StaticClass(); \
	GNativeLookupFuncs[Lookup++] = &FindIpDrvAInternetLinkNative; \
	UTcpipConnection::StaticClass(); \
	ATcpLink::StaticClass(); \
	GNativeLookupFuncs[Lookup++] = &FindIpDrvATcpLinkNative; \
	UTcpNetDriver::StaticClass(); \
	AUdpLink::StaticClass(); \
	GNativeLookupFuncs[Lookup++] = &FindIpDrvAUdpLinkNative; \

#endif // IPDRV_NATIVE_DEFS

#ifdef NATIVES_ONLY
NATIVE_INFO(AInternetLink) GIpDrvAInternetLinkNatives[] = 
{ 
	MAP_NATIVE(AInternetLink,execGetLocalIP)
	MAP_NATIVE(AInternetLink,execStringToIpAddr)
	MAP_NATIVE(AInternetLink,execIpAddrToString)
	MAP_NATIVE(AInternetLink,execGetLastError)
	MAP_NATIVE(AInternetLink,execResolve)
	MAP_NATIVE(AInternetLink,execParseURL)
	MAP_NATIVE(AInternetLink,execIsDataPending)
	{NULL,NULL}
};
IMPLEMENT_NATIVE_HANDLER(IpDrv,AInternetLink);

NATIVE_INFO(ATcpLink) GIpDrvATcpLinkNatives[] = 
{ 
	MAP_NATIVE(ATcpLink,execReadBinary)
	MAP_NATIVE(ATcpLink,execReadText)
	MAP_NATIVE(ATcpLink,execSendBinary)
	MAP_NATIVE(ATcpLink,execSendText)
	MAP_NATIVE(ATcpLink,execIsConnected)
	MAP_NATIVE(ATcpLink,execClose)
	MAP_NATIVE(ATcpLink,execOpen)
	MAP_NATIVE(ATcpLink,execListen)
	MAP_NATIVE(ATcpLink,execBindPort)
	{NULL,NULL}
};
IMPLEMENT_NATIVE_HANDLER(IpDrv,ATcpLink);

NATIVE_INFO(AUdpLink) GIpDrvAUdpLinkNatives[] = 
{ 
	MAP_NATIVE(AUdpLink,execReadBinary)
	MAP_NATIVE(AUdpLink,execReadText)
	MAP_NATIVE(AUdpLink,execSendBinary)
	MAP_NATIVE(AUdpLink,execSendText)
	MAP_NATIVE(AUdpLink,execBindPort)
	{NULL,NULL}
};
IMPLEMENT_NATIVE_HANDLER(IpDrv,AUdpLink);

#endif // NATIVES_ONLY
#endif // STATIC_LINKING_MOJO

#ifdef VERIFY_CLASS_SIZES
VERIFY_CLASS_SIZE_NODIE(AInternetLink)
VERIFY_CLASS_SIZE_NODIE(UTcpipConnection)
VERIFY_CLASS_SIZE_NODIE(ATcpLink)
VERIFY_CLASS_SIZE_NODIE(UTcpNetDriver)
VERIFY_CLASS_SIZE_NODIE(AUdpLink)
#endif // VERIFY_CLASS_SIZES
