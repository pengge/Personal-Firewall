#pragma once
#include "FilterRules.h"

extern WSPUPCALLTABLE g_UpCallTable;

extern WSPPROC_TABLE g_NextProcTable;
extern TCHAR g_szCurrentApp[MAX_PATH];

extern TCHAR	m_sProcessName[MAX_PATH]; 

int WSPAPI WSPStartup(
	WORD wVersionRequested,
	LPWSPDATA lpWSPData,
	LPWSAPROTOCOL_INFO lpProtocolInfo,
	WSPUPCALLTABLE UpcallTable,
	LPWSPPROC_TABLE lpProcTable
);


int WSPAPI MyWSPRecv(
	SOCKET			s,
	LPWSABUF		lpBuffers,
	DWORD			dwBufferCount,
	LPDWORD			lpNumberOfBytesRecvd,
	LPDWORD			lpFlags,
	LPWSAOVERLAPPED	lpOverlapped,
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
	LPWSATHREADID	lpThreadId,
	LPINT			lpErrno
);

int WSPAPI MyWSPSend(
	_In_ SOCKET s,
	_In_reads_(dwBufferCount) LPWSABUF lpBuffers,
	_In_ DWORD dwBufferCount,
	_Out_opt_ LPDWORD lpNumberOfBytesSent,
	_In_ DWORD dwFlags,
	_Inout_opt_ LPWSAOVERLAPPED lpOverlapped,
	_In_opt_ LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
	_In_opt_ LPWSATHREADID lpThreadId,
	_Out_ LPINT lpErrno
);

int WSPAPI MyWSPRecvFrom(
	_In_ SOCKET s,
	_In_reads_(dwBufferCount) LPWSABUF lpBuffers,
	_In_ DWORD dwBufferCount,
	_Out_opt_ LPDWORD lpNumberOfBytesRecvd,
	_Inout_ LPDWORD lpFlags,
	_Out_writes_bytes_to_opt_(*lpFromlen, *lpFromlen) struct sockaddr FAR * lpFrom,
	_Inout_opt_ LPINT lpFromlen,
	_Inout_opt_ LPWSAOVERLAPPED lpOverlapped,
	_In_opt_ LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
	_In_opt_ LPWSATHREADID lpThreadId,
	_Out_ LPINT lpErrno
	);

int WSPAPI MyWSPSendTo(
	_In_ SOCKET s,
	_In_reads_(dwBufferCount) LPWSABUF lpBuffers,
	_In_ DWORD dwBufferCount,
	_Out_opt_ LPDWORD lpNumberOfBytesSent,
	_In_ DWORD dwFlags,
	_In_reads_bytes_opt_(iTolen) const struct sockaddr FAR * lpTo,
	_In_ int iTolen,
	_Inout_opt_ LPWSAOVERLAPPED lpOverlapped,
	_In_opt_ LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
	_In_opt_ LPWSATHREADID lpThreadId,
	_Out_ LPINT lpErrno
	);