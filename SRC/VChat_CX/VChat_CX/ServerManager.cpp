#include "pch.h"
#include "ServerManager.h"
#include <windows.h>
#include <windows.system.h>
#include <windows.storage.streams.h>
#include <ppltasks.h>

using namespace Windows::System;
using namespace Windows::Storage::Streams;
using namespace Concurrency;

/*
* Purpose:
*
* Return:
*
* Based on https://learn.microsoft.com/en-us/windows/win32/debug/retrieving-the-last-error-code
*/
void server_manage::ServerManager::errMsg(PCTSTR  lpszFunction) {
	// Pull in error message 
	DWORD dw = GetLastError();
	std::cout << "\n" << dw << "\n";
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) & (this->lpMsgBuf),
		0, NULL);
	// Signal Error Message Box for WinForm, 

	/* Temp Error Message*/
	std::cout << lpszFunction;
	return;

}
/*
* Purpose: This function will return the current server status
*
* Return: boolean, 1 if the server is started, 0 otherwise.
*/
bool server_manage::ServerManager::get_isStarted() {
	return this->isStarted;
}

/*
Initalize the Unnamed Pipe handles

Returns Error Coded Integer

Implementation based on https://learn.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output?redirectedfrom=MSDN
*/
int server_manage::ServerManager::initPipes() {

	Platform::String^ pipeName = L"YOUR_PIPE_NAME";


	// Launch the child process
	auto process = Concurrency::create_task(ProcessLauncher::RunToCompletionAsync("ChildProcess.exe")).get();


	return 1;
}

/*
Initalize the Unnamed Pipe handles

Returns Error Coded Integer

Based on https://learn.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output?redirectedfrom=MSDN
*/
int server_manage::ServerManager::CreateServerProcess(LPSTR  cmd) {
	// Local Management Info
	STARTUPINFO siStartInfo;
	bool bSuccess = FALSE;
	wchar_t* convt_cmd;

	// Setup convt_cmd so we send over a WideChar Str
	//convt_cmd = (wchar_t*)malloc(sizeof(wchar_t)* strlen(cmd)); // Attempting to free causes heap errors?
	convt_cmd = new wchar_t[strlen(cmd)];
	mbstowcs(convt_cmd, cmd, strlen(cmd) + 1); //Plus null


	// Set up members of the PROCESS_INFORMATION structure. 
	ZeroMemory(&(this->server_proc), sizeof((this->server_proc)));

	// Set up members of the STARTUPINFO structure. 
	// This structure specifies the STDIN and STDOUT handles for redirection.
	ZeroMemory(&siStartInfo, sizeof(siStartInfo));
	siStartInfo.cb = sizeof(siStartInfo);
	siStartInfo.hStdError = this->g_hChildStd_OUT_Wr;
	siStartInfo.hStdOutput = this->g_hChildStd_OUT_Wr;
	siStartInfo.hStdInput = this->g_hChildStd_IN_Rd;
	siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

	bSuccess = CreateProcess(NULL,
		convt_cmd,     // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		TRUE,          // handles are inherited 
		0,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&(server_proc));  // receives PROCESS_INFORMATION 

	std::cout << server_proc.dwProcessId << "\n"; // Temp for Testing

	// If an error occurs, exit the application. 
	if (bSuccess == FALSE) {
		errMsg(TEXT("CreateServerProcess: Failed to create process"));
		std::cout << "\nFAILED\n";
		return -1;
	}

	// Close handles to the stdin and stdout pipes no longer needed by the child process.
	// If they are not explicitly closed, there is no way to recognize that the child process has ended.
	CloseHandle(this->g_hChildStd_OUT_Wr);
	g_hChildStd_OUT_Wr = NULL;
	CloseHandle(this->g_hChildStd_IN_Rd);
	g_hChildStd_IN_Rd = NULL;

	return 1;

}

/*
* Purpose
*
* Return: -1 if error, o.w number of successfully read bytes.
*
* Based on https://learn.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output?redirectedfrom=MSDN
*/
int server_manage::ServerManager::serverRead(char* buffObj, DWORD size) {
	DWORD dwRead;
	if (this->g_hChildStd_OUT_Rd == NULL)
		return -1;

	if (ReadFile(this->g_hChildStd_OUT_Rd, buffObj, size, &dwRead, NULL) == 0)
		return -1;

	return dwRead;
}

int server_manage::ServerManager::killServer() {

	uint16_t ret;

	if (this->isStarted == 0)
		return 1;

	// Terminate the process, ensure it is not blocking the 
	// Listening Thread
	ret = TerminateProcess((this->server_proc).hProcess, 0);

	// Close handles that have not already been closed
	if (g_hChildStd_OUT_Rd != NULL)
		CloseHandle(this->g_hChildStd_OUT_Rd);
	if (g_hChildStd_IN_Wr != NULL)
		CloseHandle(this->g_hChildStd_IN_Wr);

	return ret;
}