/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
#ifndef _Easy_RTSPClient_API_H
#define _Easy_RTSPClient_API_H

#include "../EasyCommon/EasyTypes.h"

#define	RTSP_PROG_NAME	"libEasyRTSPClient v3.0.19.0415"

/*
	_channelId:		ͨ����,��ʱ����
	_channelPtr:	ͨ����Ӧ����,��ʱ����
	_frameType:		EASY_SDK_VIDEO_FRAME_FLAG/EASY_SDK_AUDIO_FRAME_FLAG/EASY_SDK_EVENT_FRAME_FLAG/...	
	_pBuf:			�ص������ݲ��֣������÷���Demo
	_frameInfo:		֡�ṹ����
*/
typedef int (Easy_APICALL *RTSPSourceCallBack)( int _channelId, void *_channelPtr, int _frameType, char *pBuf, EASY_FRAME_INFO* _frameInfo);

#ifdef __cplusplus
extern "C"
{
#endif
	/* ��ȡ���һ�δ���Ĵ����� */
	Easy_API int Easy_APICALL EasyRTSP_GetErrCode(Easy_Handle handle);

	/* ���� */
#ifdef ANDROID
	Easy_API int Easy_APICALL EasyRTSP_Activate(char *license, char* userPtr);
#else
	Easy_API int Easy_APICALL EasyRTSP_Activate(char *license);
#endif

	/* ����RTSPClient���  ����0��ʾ�ɹ������ط�0��ʾʧ�� */
	Easy_API int Easy_APICALL EasyRTSP_Init(Easy_Handle *handle);

	/* �ͷ�RTSPClient ����ΪRTSPClient��� */
	Easy_API int Easy_APICALL EasyRTSP_Deinit(Easy_Handle *handle);

	/* �������ݻص� */
	Easy_API int Easy_APICALL EasyRTSP_SetCallback(Easy_Handle handle, RTSPSourceCallBack _callback);

	/* �������� */
	Easy_API int Easy_APICALL EasyRTSP_OpenStream(Easy_Handle handle, int _channelid, char *_url, EASY_RTP_CONNECT_TYPE _connType, unsigned int _mediaType, char *_username, char *_password, void *userPtr, int _reconn/*1000��ʾ������,���������Ͽ��Զ�����, ����ֵΪ���Ӵ���*/, int outRtpPacket/*Ĭ��Ϊ0,���ص����������֡, ���Ϊ1,�����RTP��*/, int heartbeatType/*0x00:���������� 0x01:OPTIONS 0x02:GET_PARAMETER*/, int _verbosity/*��־��ӡ����ȼ���0��ʾ�����*/);
	
	/* �ر������� */
	Easy_API int Easy_APICALL EasyRTSP_CloseStream(Easy_Handle handle);

#ifdef __cplusplus
}
#endif

#endif