#pragma once


#include "getsps.h"
#include "EasyRTSPClient/EasyRTSPClientAPI.h"
#include "EasyRTSPServer/EasyRtspServerAPI.h"
#include <time.h>
#ifdef _WIN32
//===============Windows==============
#if 0
//32位程序使用Win32文件夹下链接库
#pragma comment(lib, "EasyRTSPClient/Win32/libEasyRTSPClient.lib")
#pragma comment(lib, "EasyRTSPServer/Win32/libEasyRTSPServer.lib")
#else
//64位程序使用Win64文件夹下链接库
#pragma comment(lib, "EasyRTSPClient/Win64/libEasyRTSPClient.lib")
#pragma comment(lib, "EasyRTSPServer/Win64/libEasyRTSPServer.lib")
#endif
#else
//===============Linux=================
#include <unistd.h>
#define	Sleep(x)	{usleep(x*1000);}
#endif



#ifdef _WIN32
static const char *RTSPCLIENT_LIC =	"6D75724D7A4969576B5A75416C2F4A656F51316F5065314659584E35556C525455454E73615756756443356C65475570567778576F502B392F32566863336B3D";
static const char *RTSPSERVER_LIC =	"243AE7D5A4A727B5D3264F530D2C51A430303237463235453436303030303030313730303030303034353631373337393533373437323635363136443639364536373533363537323736363537323245363537383635383032413235354430303030303030303739373336313635";
#else
static const char *RTSPCLIENT_LIC =	"6D75724D7A4969576B5A754132594E656F58776D4A65314659584E35556C525455454E73615756756443356C6547556A567778576F502B6C2F69426C59584E35";
static const char *RTSPSERVER_LIC =	"243AE7D5A4A727B5D3264F530D2C51A43830413441393545354130303030303031333030303030303435363137333739353337343732363536313644363936453637353336353732373636353732383032413235354430303030303030303739373336313635";
#endif


typedef struct __RTSP_CHANNEL_T
{
	char		url[256];
	char		resourcename[256];
	char		username[36];
	char		password[36];
	
	EASY_RTSPSERVER_MEDIA_INFO_T		mediaInfo;		//源媒体信息

	Easy_Handle	rtspClientHandle;			//rtsp客户端句柄

	int			status;		//
	EASY_CHANNEL_HANDLE	channelHandle;
}RTSP_CHANNEL_T;





class EasyStreamingServer
{
public:
	EasyStreamingServer(void);
	~EasyStreamingServer(void);

	int		Startup(int rtspPort);
	void	Shutdown();

	void	ResetChannel(int channelId);
};

