#ifndef __DBGLINK_H_200801020926__
#define __DBGLINK_H_200801020926__

#ifdef DBGLINK_EXPORTS
#define DBGLINK_API __declspec(dllexport)
#else
#define DBGLINK_API __declspec(dllimport)
#endif


#ifdef _DEBUG
#define ENABLE_DEBUG		
#endif

#define MAX_DEBUG_TEXT		1024

#ifdef ENABLE_DEBUG
#define LOG			DbgLink_Log
#define DebugText	DbgLink_SendText
#else
#define LOG			1?false:DbgLink_Log
#define DebugText	1?false:DbgLink_SendText
#endif

#ifdef __cplusplus
extern "C" {
#else
typedef char bool;
#endif


DBGLINK_API void DbgLink_SetWaitTime(unsigned long dwMilliseconds/* 50 ms */);
DBGLINK_API unsigned long DbgLink_GetIDByTime(char cDay, char cHour, char cMinute, unsigned char cRand/*0~255*/);
#define DEBUGLINK_TYPE_INFO		0
#define DEBUGLINK_TYPE_WARNING	1
#define DEBUGLINK_TYPE_ERROR	2
#define DEBUGLINK_TYPE_FAULT	3
/* iType: 
	0: Information
	1: Warning message
	2: Error message
	3: Fault message
*/
DBGLINK_API bool DbgLink_SendText(unsigned long dwID, int iType, const char * fmt, ...);
DBGLINK_API bool DbgLink_SendTextV(unsigned long dwID, int iType, const char * fmt, va_list argList);
// 允许记录发送错误信息到"C:\DbgLink.log
DBGLINK_API void DbgLink_LogSendError(bool bLog);

DBGLINK_API bool DbgLink_ClearLog(const char* lpszLogFile);
DBGLINK_API bool DbgLink_Log(const char* lpszLogFile, const char * fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // __DBGLINK_H_200801020926__
